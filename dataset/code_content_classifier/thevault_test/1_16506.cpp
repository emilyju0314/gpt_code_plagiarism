unsigned int OneQuery(HANDLE hProcess)
{
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (NULL == hProcess)
        return 0;
    if (GetProcessMemoryInfo(hProcess, (PPROCESS_MEMORY_COUNTERS)&pmc, sizeof(pmc)))
        return (unsigned)pmc.PrivateUsage;
    return 0;
}