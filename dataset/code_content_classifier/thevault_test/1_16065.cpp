VkResult CommandBuffer::PreBeginCommandBuffer(
    VkCommandBuffer wrappedCommandBuffer, VkCommandBuffer commandBuffer,
    VkCommandBufferBeginInfo const* pBeginInfo) {
  // Reset state on Begin.
  Reset();
  tracker_.TrackPreBeginCommandBuffer(commandBuffer, pBeginInfo);
  return VK_SUCCESS;
}