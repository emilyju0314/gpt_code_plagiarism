void HelloVulkan::createLanternIndirectBuffer()
{
  assert(m_lanternCount > 0);
  assert(m_lanternCount == m_lanterns.size());

  // m_alloc behind the scenes uses cmdBuf to transfer data to the buffer.
  nvvk::CommandPool cmdBufGet(m_device, m_graphicsQueueIndex);
  VkCommandBuffer   cmdBuf = cmdBufGet.createCommandBuffer();

  using Usage             = VkBufferUsageFlagBits;
  m_lanternIndirectBuffer = m_alloc.createBuffer(sizeof(LanternIndirectEntry) * m_lanternCount,
                                                 VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT
                                                     | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
                                                 VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

  std::vector<LanternIndirectEntry> entries(m_lanternCount);
  for(size_t i = 0; i < m_lanternCount; ++i)
    entries[i].lantern = m_lanterns[i];
  vkCmdUpdateBuffer(cmdBuf, m_lanternIndirectBuffer.buffer, 0, entries.size() * sizeof entries[0], entries.data());

  cmdBufGet.submitAndWait(cmdBuf);
}