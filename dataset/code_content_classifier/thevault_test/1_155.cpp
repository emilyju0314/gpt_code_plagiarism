void VulkanDevice::copyVkBuffer(VkBuffer *src, VkBuffer *dst, VkBufferCopy *copyRegion) {

    VkCommandBuffer copyCmd = createCommandBuffer(VK_COMMAND_BUFFER_LEVEL_PRIMARY, true);
    vkCmdCopyBuffer(copyCmd, *src, *dst, 1, copyRegion);
    flushCommandBuffer(copyCmd, transferQueue, true);

}