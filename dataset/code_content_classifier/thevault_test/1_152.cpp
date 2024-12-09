VkResult
VulkanDevice::createBuffer(VkBufferUsageFlags usageFlags, VkMemoryPropertyFlags memoryPropertyFlags, VkDeviceSize size,
                           VkBuffer *buffer, VkDeviceMemory *memory, void *data) {
    // Create the buffer handle
    VkBufferCreateInfo bufferCreateInfo = Populate::bufferCreateInfo(usageFlags, size);
    bufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    if (vkCreateBuffer(logicalDevice, &bufferCreateInfo, nullptr, buffer) != VK_SUCCESS)
        throw std::runtime_error("Failed to create Buffer");

    // Create the memory backing up the buffer handle
    VkMemoryRequirements memReqs;
    vkGetBufferMemoryRequirements(logicalDevice, *buffer, &memReqs);
    assert(size <= memReqs.size);
    VkMemoryAllocateInfo memAlloc = Populate::memoryAllocateInfo();
    memAlloc.allocationSize = memReqs.size;

    // Find a memory type index that fits the properties of the buffer
    memAlloc.memoryTypeIndex = getMemoryType(memReqs.memoryTypeBits, memoryPropertyFlags);
    // If the buffer has VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT set we also need to enable the appropriate flag during allocation
    VkMemoryAllocateFlagsInfoKHR allocFlagsInfo{};
    if (usageFlags & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) {
        allocFlagsInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR;
        allocFlagsInfo.flags = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR;
        memAlloc.pNext = &allocFlagsInfo;
    }
    if (VK_SUCCESS != vkAllocateMemory(logicalDevice, &memAlloc, nullptr, memory))
        throw std::runtime_error("Failed to allocate Buffer memory");

    // If a pointer to the buffer data has been passed, map the buffer and copy over the data
    if (data != nullptr) {
        void *mapped;
        if (vkMapMemory(logicalDevice, *memory, 0, size, 0, &mapped) != VK_SUCCESS)
            throw std::runtime_error("Failed to Map Buffer memory");
        memcpy(mapped, data, size);
        // If host coherency hasn't been requested, do a manual flush to make writes visible
        if ((memoryPropertyFlags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == 0) {
            VkMappedMemoryRange mappedRange = Populate::mappedMemoryRange();
            mappedRange.memory = *memory;
            mappedRange.offset = 0;
            mappedRange.size = size;
            vkFlushMappedMemoryRanges(logicalDevice, 1, &mappedRange);
        }
        vkUnmapMemory(logicalDevice, *memory);
    }

    // Attach the memory to the buffer object
    if (vkBindBufferMemory(logicalDevice, *buffer, *memory, 0) != VK_SUCCESS)
        throw std::runtime_error("Failed to bind buffer memory");

    return VK_SUCCESS;
}