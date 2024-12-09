const AffinitySet* GCToOSInterface::SetGCThreadsAffinitySet(uintptr_t configAffinityMask, const AffinitySet* configAffinitySet)
{
    // When the configAffinitySet is not empty, enforce the cpu groups
    if (CanEnableGCCPUGroups())
    {
        if (!configAffinitySet->IsEmpty())
        {
            // Update the process affinity set using the configured set
            for (size_t i = 0; i < MAX_SUPPORTED_CPUS; i++)
            {
                if (g_processAffinitySet.Contains(i) && !configAffinitySet->Contains(i))
                {
                    g_processAffinitySet.Remove(i);
                }
            }
        }
    }
    else
    {
        if (configAffinityMask != 0)
        {
            // Update the process affinity set using the configured mask
            for (size_t i = 0; i < 8 * sizeof(uintptr_t); i++)
            {
                if (g_processAffinitySet.Contains(i) && ((configAffinityMask & ((uintptr_t)1 << i)) == 0))
                {
                    g_processAffinitySet.Remove(i);
                }
            }
        }
    }

    return &g_processAffinitySet;
}