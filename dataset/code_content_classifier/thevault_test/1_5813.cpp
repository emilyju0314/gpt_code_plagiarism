VkResult Memory::GetCommitment(
    VkDeviceSize* pCommittedMemoryInBytes)
{
    VK_ASSERT(pCommittedMemoryInBytes != nullptr);

    // We never allocate memory lazily, so just return the size of the memory object
    *pCommittedMemoryInBytes = m_info.size;

    return VK_SUCCESS;
}