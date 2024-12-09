VkCommandBuffer VulkanDevice::createCommandBuffer(VkCommandBufferLevel level, VkCommandPool pool, bool begin) {
    VkCommandBufferAllocateInfo cmdBufAllocateInfo = Populate::commandBufferAllocateInfo(pool, level, 1);
    VkCommandBuffer cmdBuffer;
    if (vkAllocateCommandBuffers(logicalDevice, &cmdBufAllocateInfo, &cmdBuffer) != VK_SUCCESS)
        throw std::runtime_error("Failed to allocate command buffers");
    // If requested, also start recording for the new command buffer
    if (begin) {
        VkCommandBufferBeginInfo cmdBufInfo = Populate::commandBufferBeginInfo();
        if (vkBeginCommandBuffer(cmdBuffer, &cmdBufInfo) != VK_SUCCESS)
            throw std::runtime_error("Failed to begin command buffer");
    }
    return cmdBuffer;
}