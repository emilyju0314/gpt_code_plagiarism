uint32_t GCToOSInterface::GetTotalProcessorCount()
{
    if (CanEnableGCCPUGroups())
    {
        return g_nProcessors;
    }
    else
    {
        return g_SystemInfo.dwNumberOfProcessors;
    }
}