void HelloVulkan::createLanternIndirectCompPipeline()
{
  // Compile compute shader and package as stage.
  VkShaderModule computeShader =
      nvvk::createShaderModule(m_device, nvh::loadFile("spv/lanternIndirect.comp.spv", true, defaultSearchPaths, true));
  VkPipelineShaderStageCreateInfo stageInfo{VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO};
  stageInfo.stage  = VK_SHADER_STAGE_COMPUTE_BIT;
  stageInfo.module = computeShader;
  stageInfo.pName  = "main";

  // Set up push constant and pipeline layout.
  constexpr auto      pushSize   = static_cast<uint32_t>(sizeof(m_lanternIndirectPushConstants));
  VkPushConstantRange pushCRange = {VK_SHADER_STAGE_COMPUTE_BIT, 0, pushSize};
  static_assert(pushSize <= 128, "Spec guarantees only 128 byte push constant");
  VkPipelineLayoutCreateInfo layoutInfo{VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO};
  layoutInfo.setLayoutCount         = 1;
  layoutInfo.pSetLayouts            = &m_lanternIndirectDescSetLayout;
  layoutInfo.pushConstantRangeCount = 1;
  layoutInfo.pPushConstantRanges    = &pushCRange;
  vkCreatePipelineLayout(m_device, &layoutInfo, nullptr, &m_lanternIndirectCompPipelineLayout);

  // Create compute pipeline.
  VkComputePipelineCreateInfo pipelineInfo{VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO};
  pipelineInfo.stage  = stageInfo;
  pipelineInfo.layout = m_lanternIndirectCompPipelineLayout;
  vkCreateComputePipelines(m_device, {}, 1, &pipelineInfo, nullptr, &m_lanternIndirectCompPipeline);

  vkDestroyShaderModule(m_device, computeShader, nullptr);
}