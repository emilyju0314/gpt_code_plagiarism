VkCommandPool VulkanDevice::createCommandPool(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags createFlags) {
    VkCommandPoolCreateInfo cmdPoolInfo = {};
    cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    cmdPoolInfo.queueFamilyIndex = queueFamilyIndex;
    cmdPoolInfo.flags = createFlags;
    VkCommandPool cmdPool;
    VkResult result = vkCreateCommandPool(logicalDevice, &cmdPoolInfo, nullptr, &cmdPool);
    if (result != VK_SUCCESS)
        throw std::runtime_error("Failed to create command pool");

    return cmdPool;
}