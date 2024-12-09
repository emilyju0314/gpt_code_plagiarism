void Buffer::setupDescriptor(VkDeviceSize size, VkDeviceSize offset) {
    descriptorBufferInfo.offset = offset;
    descriptorBufferInfo.buffer = buffer;
    descriptorBufferInfo.range = size;
}