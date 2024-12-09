bool GCToOSInterface::Initialize()
{
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    g_SystemInfo.dwNumberOfProcessors = systemInfo.dwNumberOfProcessors;
    g_SystemInfo.dwPageSize = systemInfo.dwPageSize;
    g_SystemInfo.dwAllocationGranularity = systemInfo.dwAllocationGranularity;

    assert(systemInfo.dwPageSize == 0x1000);

    InitNumaNodeInfo();
    InitCPUGroupInfo();

    if (CanEnableGCCPUGroups())
    {
        // When CPU groups are enabled, then the process is not bound by the process affinity set at process launch.
        // Set the initial affinity mask so that all processors are enabled.
        for (size_t i = 0; i < g_nProcessors; i++)
        {
            g_processAffinitySet.Add(i);
        }
    }
    else
    {
        // When CPU groups are disabled, the process affinity mask specified at the process launch cannot be
        // escaped.
        uintptr_t pmask, smask;
        if (!!::GetProcessAffinityMask(::GetCurrentProcess(), (PDWORD_PTR)&pmask, (PDWORD_PTR)&smask))
        {
            pmask &= smask;

            for (size_t i = 0; i < 8 * sizeof(uintptr_t); i++)
            {
                if ((pmask & ((uintptr_t)1 << i)) != 0)
                {
                    g_processAffinitySet.Add(i);
                }
            }
        }
    }

    return true;
}