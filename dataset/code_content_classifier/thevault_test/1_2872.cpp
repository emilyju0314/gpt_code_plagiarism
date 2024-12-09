void* GCToOSInterface::VirtualReserveAndCommitLargePages(size_t size)
{
    void* pRetVal = nullptr;

    if (!g_SeLockMemoryPrivilegeAcquired)
    {
        if (!InitLargePagesPrivilege())
        {
            return nullptr;
        }

        g_SeLockMemoryPrivilegeAcquired = true;
    }

    SIZE_T largePageMinimum = GetLargePageMinimum();
    size = (size + (largePageMinimum - 1)) & ~(largePageMinimum - 1);

    return ::VirtualAlloc(nullptr, size, MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES, PAGE_READWRITE);
}