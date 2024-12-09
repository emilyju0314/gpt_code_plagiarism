VkResult Memory::Map(
    VkFlags      flags,
    VkDeviceSize offset,
    VkDeviceSize size,
    void**       ppData)
{
    VkResult result = VK_SUCCESS;

    // According to spec, "memory must not have been allocated with multiple instances"
    // if it is multi-instance allocation, we should just return VK_ERROR_MEMORY_MAP_FAILED
    if (!m_multiInstance)
    {
        Pal::Result palResult = Pal::Result::Success;
        if (PalMemory(m_primaryDeviceIndex) != nullptr)
        {
            void* pData;

            palResult = PalMemory(m_primaryDeviceIndex)->Map(&pData);

            if (palResult == Pal::Result::Success)
            {
                *ppData = Util::VoidPtrInc(pData, static_cast<size_t>(offset));

            }
            result = (palResult == Pal::Result::Success) ? VK_SUCCESS : VK_ERROR_MEMORY_MAP_FAILED;
        }
        else
        {
            result = VK_ERROR_MEMORY_MAP_FAILED;
        }
    }
    else
    {
        result = VK_ERROR_MEMORY_MAP_FAILED;
    }

    return result;
}