void HelloVulkan::createLanternIndirectDescriptorSet()
{
  // Lantern buffer (binding = 0)
  m_lanternIndirectDescSetLayoutBind.addBinding(0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1, VK_SHADER_STAGE_COMPUTE_BIT);

  m_lanternIndirectDescPool      = m_lanternIndirectDescSetLayoutBind.createPool(m_device);
  m_lanternIndirectDescSetLayout = m_lanternIndirectDescSetLayoutBind.createLayout(m_device);

  VkDescriptorSetAllocateInfo allocateInfo{VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO};
  allocateInfo.descriptorPool     = m_lanternIndirectDescPool;
  allocateInfo.descriptorSetCount = 1;
  allocateInfo.pSetLayouts        = &m_lanternIndirectDescSetLayout;
  vkAllocateDescriptorSets(m_device, &allocateInfo, &m_lanternIndirectDescSet);


  assert(m_lanternIndirectBuffer.buffer);
  VkDescriptorBufferInfo lanternBufferInfo{m_lanternIndirectBuffer.buffer, 0, m_lanternCount * sizeof(LanternIndirectEntry)};

  std::vector<VkWriteDescriptorSet> writes;
  writes.emplace_back(m_lanternIndirectDescSetLayoutBind.makeWrite(m_lanternIndirectDescSet, 0, &lanternBufferInfo));
  vkUpdateDescriptorSets(m_device, static_cast<uint32_t>(writes.size()), writes.data(), 0, nullptr);
}