void HelloVulkan::createRtShaderBindingTable()
{
  auto     groupCount      = static_cast<uint32_t>(m_rtShaderGroups.size());  // 4 shaders: raygen, 2 miss, chit
  uint32_t groupHandleSize = m_rtProperties.shaderGroupHandleSize;            // Size of a program identifier
  // Compute the actual size needed per SBT entry (round-up to alignment needed).
  uint32_t groupSizeAligned = nvh::align_up(groupHandleSize, m_rtProperties.shaderGroupBaseAlignment);
  // Bytes needed for the SBT.
  uint32_t sbtSize = groupCount * groupSizeAligned;

  // Fetch all the shader handles used in the pipeline. This is opaque data,/ so we store it in a vector of bytes.
  // The order of handles follow the stage entry.
  std::vector<uint8_t> shaderHandleStorage(sbtSize);
  auto                 result = vkGetRayTracingShaderGroupHandlesKHR(m_device, m_rtPipeline, 0, groupCount, sbtSize, shaderHandleStorage.data());

  assert(result == VK_SUCCESS);

  // Allocate a buffer for storing the SBT. Give it a debug name for NSight.
  m_rtSBTBuffer = m_alloc.createBuffer(sbtSize,
                                       VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT
                                           | VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR,
                                       VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
  m_debug.setObjectName(m_rtSBTBuffer.buffer, std::string("SBT"));

  // Map the SBT buffer and write in the handles.
  void* mapped = m_alloc.map(m_rtSBTBuffer);
  auto* pData  = reinterpret_cast<uint8_t*>(mapped);
  for(uint32_t g = 0; g < groupCount; g++)
  {
    memcpy(pData, shaderHandleStorage.data() + g * groupHandleSize, groupHandleSize);
    pData += groupSizeAligned;
  }
  m_alloc.unmap(m_rtSBTBuffer);
  m_alloc.finalizeAndReleaseStaging();
}