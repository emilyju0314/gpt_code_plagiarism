void VulkanDevice::flushCommandBuffer(VkCommandBuffer commandBuffer, VkQueue queue, VkCommandPool pool, bool free) {
    if (commandBuffer == VK_NULL_HANDLE) {
        return;
    }

    if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS) throw std::runtime_error("Failed to end command buffer");

    VkSubmitInfo submitInfo = Populate::submitInfo();
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer;
    // Create fence to ensure that the command buffer has finished executing
    VkFenceCreateInfo fenceInfo = Populate::fenceCreateInfo(0);
    VkFence fence;
    if (vkCreateFence(logicalDevice, &fenceInfo, nullptr, &fence) != VK_SUCCESS)
        throw std::runtime_error("Failed to create fence");
    // Submit to the queue
    if (vkQueueSubmit(queue, 1, &submitInfo, fence) != VK_SUCCESS)
        throw std::runtime_error("Failed to submit to queue");
    // Wait for the fence to signal that command buffer has finished executing
    if (vkWaitForFences(logicalDevice, 1, &fence, VK_TRUE, UINT64_MAX) != VK_SUCCESS)
        throw std::runtime_error("Failed to wait for fence");
    vkDestroyFence(logicalDevice, fence, nullptr);
    if (free) {
        vkFreeCommandBuffers(logicalDevice, pool, 1, &commandBuffer);
    }
}