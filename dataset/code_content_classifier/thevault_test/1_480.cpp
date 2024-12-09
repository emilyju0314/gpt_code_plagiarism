BOOL DisguiseProcess(DWORD dwProcessId, wchar_t* lpwszPath, wchar_t* lpwszCmd) {
    HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
    std::cout << dwProcessId << std::endl;
    if (NULL == hProcess) {
        return FALSE;
    }
    PROCESS_BASIC_INFORMATION pbi = { 0 };
    PEB peb = { 0 };
    RTL_USER_PROCESS_PARAMETERS Param = { 0 };
    USHORT usCmdLen = 0;
    USHORT usPathLen = 0;

    // The needed Method is defined in ntdll.dll and we need to use LoadLibrary and GetProcessAddress to
    // fetch this method dynamiclly, see `https://docs.microsoft.com/en-us/windows/win32/api/winternl/
    // nf-winternl-ntqueryinformationprocess` for help.
    HMODULE hModule = LoadLibraryA("Ntdll.dll");
    PFUN_NtQueryInformationProcess pfun = (PFUN_NtQueryInformationProcess)GetProcAddress(hModule, "NtQueryInformationProcess");
    if (NULL == pfun)
    {
        return FALSE;
    }
    // Get Information of the given process.
    NTSTATUS status = pfun(hProcess, ProcessBasicInformation, &pbi, sizeof(pbi), NULL);
    if (!NT_SUCCESS(status))
    {
        return FALSE;
    }

    std::cout << GetLastError() << std::endl;

    // When reading/writing memory of other process.We should use ReadProcessMemory/WriteProcessMemory
    // instead of pointers beacause pointers are just locations pointing to the current process.

    ::ReadProcessMemory(hProcess, pbi.PebBaseAddress, &peb, sizeof(peb), NULL);
    ::ReadProcessMemory(hProcess, peb.ProcessParameters, &Param, sizeof(Param), NULL);

    usCmdLen = 2 + 2 * ::wcslen(lpwszCmd);
    ::WriteProcessMemory(hProcess, Param.CommandLine.Buffer, lpwszCmd, usCmdLen, NULL);
    ::WriteProcessMemory(hProcess, &Param.CommandLine.Length, &usCmdLen, sizeof(usCmdLen), NULL);

    usPathLen = 2 + 2 * ::wcslen(lpwszPath);
    ::WriteProcessMemory(hProcess, Param.ImagePathName.Buffer, lpwszPath, usPathLen, NULL);
    ::WriteProcessMemory(hProcess, &Param.ImagePathName.Length, &usPathLen, sizeof(usPathLen), NULL);
    return TRUE;
}