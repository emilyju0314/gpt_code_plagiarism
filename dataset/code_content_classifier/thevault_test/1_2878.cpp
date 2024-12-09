uint64_t GCToOSInterface::GetPhysicalMemoryLimit(bool* is_restricted)
{
    if (is_restricted)
        *is_restricted = false;

    size_t restricted_limit = GetRestrictedPhysicalMemoryLimit();
    if (restricted_limit != 0)
    {
        if (is_restricted && !g_UseRestrictedVirtualMemory)
            *is_restricted = true;

        return restricted_limit;
    }

    MEMORYSTATUSEX memStatus;
    GetProcessMemoryLoad(&memStatus);
    assert(memStatus.ullTotalPhys != 0);
    return memStatus.ullTotalPhys;
}