unsigned int OneQueryMP(HANDLE hProcess)
{
    unsigned int memUsage = 0;
    TCHAR monitoredProcessName[MAX_PATH];
    GetProcessImageFileName(hProcess, monitoredProcessName, sizeof(monitoredProcessName)/sizeof(TCHAR));
    LPTSTR shortProcessName = PathFindFileName(monitoredProcessName);
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    HANDLE hFoundProcess;
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
        return 0;

    // Calculate how many process identifiers were returned.
    cProcesses = cbNeeded / sizeof(DWORD);
    // find existing process
    for (unsigned int i = 0; i < cProcesses; i++)
        if (aProcesses[i] != 0) {
            DWORD retVal = 0;
            TCHAR foundProcessName[MAX_PATH];

            // Get a handle to the process.
            hFoundProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, aProcesses[i]);

            // Get the process name.
            if (NULL != hFoundProcess) {
                HMODULE hMod;
                DWORD cbNeeded;

                if (EnumProcessModules(hFoundProcess, &hMod, sizeof(hMod), &cbNeeded)) {
                    GetModuleBaseName(hFoundProcess, hMod, foundProcessName, sizeof(foundProcessName)/sizeof(TCHAR));
                    if (wcsstr(foundProcessName, shortProcessName))
                        memUsage += OneQuery(hFoundProcess);
                }
            }
            CloseHandle(hFoundProcess);
        }
    return memUsage;
}