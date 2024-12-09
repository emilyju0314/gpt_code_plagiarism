void HelloVulkan::raytrace(const VkCommandBuffer& cmdBuf, const nvmath::vec4f& clearColor)
{
  // Before tracing rays, we need to dispatch the compute shaders that
  // fill in the ray trace indirect parameters for each lantern pass.

  // First, barrier before, ensure writes aren't visible to previous frame.
  VkBufferMemoryBarrier bufferBarrier{VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER};
  bufferBarrier.srcAccessMask       = VK_ACCESS_INDIRECT_COMMAND_READ_BIT;
  bufferBarrier.dstAccessMask       = VK_ACCESS_SHADER_WRITE_BIT;
  bufferBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  bufferBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  bufferBarrier.buffer              = m_lanternIndirectBuffer.buffer;
  bufferBarrier.offset              = 0;
  bufferBarrier.size                = m_lanternCount * sizeof m_lanterns[0];
  vkCmdPipelineBarrier(cmdBuf,
                       VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT,   //
                       VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,  //
                       VkDependencyFlags(0),                  //
                       0, nullptr, 1, &bufferBarrier, 0, nullptr);

  // Bind compute shader, update push constant and descriptors, dispatch compute.
  vkCmdBindPipeline(cmdBuf, VK_PIPELINE_BIND_POINT_COMPUTE, m_lanternIndirectCompPipeline);
  nvmath::mat4f view                          = getViewMatrix();
  m_lanternIndirectPushConstants.viewRowX     = view.row(0);
  m_lanternIndirectPushConstants.viewRowY     = view.row(1);
  m_lanternIndirectPushConstants.viewRowZ     = view.row(2);
  m_lanternIndirectPushConstants.proj         = getProjMatrix();
  m_lanternIndirectPushConstants.nearZ        = nearZ;
  m_lanternIndirectPushConstants.screenX      = m_size.width;
  m_lanternIndirectPushConstants.screenY      = m_size.height;
  m_lanternIndirectPushConstants.lanternCount = int32_t(m_lanternCount);
  vkCmdPushConstants(cmdBuf, m_lanternIndirectCompPipelineLayout, VK_SHADER_STAGE_COMPUTE_BIT, 0,
                     sizeof(LanternIndirectPushConstants), &m_lanternIndirectPushConstants);
  vkCmdBindDescriptorSets(cmdBuf, VK_PIPELINE_BIND_POINT_COMPUTE, m_lanternIndirectCompPipelineLayout, 0, 1,
                          &m_lanternIndirectDescSet, 0, nullptr);
  vkCmdDispatch(cmdBuf, 1, 1, 1);

  // Ensure compute results are visible when doing indirect ray trace.
  bufferBarrier.srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT;
  bufferBarrier.dstAccessMask = VK_ACCESS_INDIRECT_COMMAND_READ_BIT;
  vkCmdPipelineBarrier(cmdBuf,
                       VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,  //
                       VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT,   //
                       VkDependencyFlags(0),                  //
                       0, nullptr, 1, &bufferBarrier, 0, nullptr);


  // Now move on to the actual ray tracing.
  m_debug.beginLabel(cmdBuf, "Ray trace");

  // Initialize push constant values
  m_pcRay.clearColor        = clearColor;
  m_pcRay.lightPosition     = m_pcRaster.lightPosition;
  m_pcRay.lightIntensity    = m_pcRaster.lightIntensity;
  m_pcRay.lightType         = m_pcRaster.lightType;
  m_pcRay.lanternPassNumber = -1;  // Global non-lantern pass
  m_pcRay.screenX           = m_size.width;
  m_pcRay.screenY           = m_size.height;
  m_pcRay.lanternDebug      = m_lanternDebug;

  std::vector<VkDescriptorSet> descSets{m_rtDescSet, m_descSet};
  vkCmdBindPipeline(cmdBuf, VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR, m_rtPipeline);
  vkCmdBindDescriptorSets(cmdBuf, VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR, m_rtPipelineLayout, 0,
                          (uint32_t)descSets.size(), descSets.data(), 0, nullptr);
  vkCmdPushConstants(cmdBuf, m_rtPipelineLayout,
                     VK_SHADER_STAGE_RAYGEN_BIT_KHR | VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR | VK_SHADER_STAGE_MISS_BIT_KHR,
                     0, sizeof(PushConstantRay), &m_pcRay);


  vkCmdTraceRaysKHR(cmdBuf, &m_rgenRegion, &m_missRegion, &m_hitRegion, &m_callRegion, m_size.width, m_size.height, 1);


  // Lantern passes, ensure previous pass completed, then add light contribution from each lantern.
  for(int i = 0; i < static_cast<int>(m_lanternCount); ++i)
  {
    // Barrier to ensure previous pass finished.
    VkImage                 offscreenImage{m_offscreenColor.image};
    VkImageSubresourceRange colorRange{VK_IMAGE_ASPECT_COLOR_BIT, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS};
    VkImageMemoryBarrier imageBarrier{VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER};
    imageBarrier.oldLayout           = VK_IMAGE_LAYOUT_GENERAL;
    imageBarrier.newLayout           = VK_IMAGE_LAYOUT_GENERAL;
    imageBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    imageBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    imageBarrier.image               = offscreenImage;
    imageBarrier.subresourceRange    = colorRange;
    imageBarrier.srcAccessMask       = VK_ACCESS_SHADER_WRITE_BIT;
    imageBarrier.dstAccessMask       = VK_ACCESS_SHADER_READ_BIT;
    vkCmdPipelineBarrier(cmdBuf,
                         VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR,  //
                         VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR,  //
                         VkDependencyFlags(0),                          //
                         0, nullptr, 0, nullptr, 1, &imageBarrier);

    // Set lantern pass number.
    m_pcRay.lanternPassNumber = i;
    vkCmdPushConstants(cmdBuf, m_rtPipelineLayout,
                       VK_SHADER_STAGE_RAYGEN_BIT_KHR | VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR | VK_SHADER_STAGE_MISS_BIT_KHR,
                       0, sizeof(PushConstantRay), &m_pcRay);


    VkDeviceAddress indirectDeviceAddress =
        nvvk::getBufferDeviceAddress(m_device, m_lanternIndirectBuffer.buffer) + i * sizeof(LanternIndirectEntry);

    // Execute lantern pass.
    vkCmdTraceRaysIndirectKHR(cmdBuf, &m_rgenRegion, &m_missRegion, &m_hitRegion, &m_callRegion, indirectDeviceAddress);
  }

  m_debug.endLabel(cmdBuf);
}