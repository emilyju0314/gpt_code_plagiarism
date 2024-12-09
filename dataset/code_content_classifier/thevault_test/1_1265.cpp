void Raytracer::updateRtDescriptorSet(const VkImageView& outputImage)
{
  VkDescriptorImageInfo imageInfo{{}, outputImage, VK_IMAGE_LAYOUT_GENERAL};
  VkWriteDescriptorSet  wds = m_rtDescSetLayoutBind.makeWrite(m_rtDescSet, RtxBindings::eOutImage, &imageInfo);
  vkUpdateDescriptorSets(m_device, 1, &wds, 0, nullptr);
}