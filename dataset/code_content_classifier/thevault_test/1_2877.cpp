size_t GCToOSInterface::GetVirtualMemoryLimit()
{
    MEMORYSTATUSEX memStatus;
    GetProcessMemoryLoad(&memStatus);
    assert(memStatus.ullAvailVirtual != 0);
    return (size_t)memStatus.ullAvailVirtual;
}