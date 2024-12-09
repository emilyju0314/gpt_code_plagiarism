static uint32_t GetMemoryTypeOccurence(uint32_t index, const VkPhysicalDeviceMemoryProperties& props)
{
    assert(index < props.memoryTypeCount);

    uint32_t occurrence = 1;

    for (uint32_t i = 0; i < index; ++i)
    {
        if (props.memoryTypes[index].propertyFlags == props.memoryTypes[i].propertyFlags)
        {
            ++occurrence;
        }
    }

    return occurrence;
}