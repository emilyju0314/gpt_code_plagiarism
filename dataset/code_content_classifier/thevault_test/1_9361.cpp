HRESULT GetFullPathFromImagePath
(
    LPWSTR              ImagePath,
    LPWSTR              DriverFullPath,
    UINT                cchFullPath
)
{
    HRESULT hr = S_OK;
    //
    // First, check if the ImagePath uses either of the well-known kernel
    // DosDevices prefixes.  If so, skip over those first since
    // GetFileAttributes would succeed, leading us to think it is a valid DOS
    // path, and GetFullPathName handles these incorrectly anyways.  Don't
    // bother handling the user DosDevices formats since it would be invalid to
    // specify that format for the ImagePath of a kernel module.
    //
    LPWSTR pImagePath = (LPWSTR)ImagePath;

    const wchar_t* DosDevicesPath =  L"\\DosDevices\\";
    const wchar_t* QuestionPath = L"\\??\\";
    if (_wcsnicmp(pImagePath,
        DosDevicesPath,
        static_cast<int>(wcslen(DosDevicesPath))) == 0)
    {
        pImagePath += wcslen(DosDevicesPath);
    }
    else if (_wcsnicmp(pImagePath,
        QuestionPath,
        static_cast<int>(wcslen(QuestionPath))) == 0)
    {
        pImagePath += wcslen(QuestionPath);
    }

    //
    // Check if the ImagePath happens to be a valid full path.
    //
    if (GetFileAttributesW(pImagePath) != 0xFFFFFFFF)
    {
        if (!VERIFY_IS_TRUE(GetFullPathNameW(pImagePath, cchFullPath, DriverFullPath, nullptr)))
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            return hr;
        }
        return hr;
    }

    //
    // If the ImagePath starts with "\SystemRoot" or "%SystemRoot%" then
    // remove those values.
    //
    LPWSTR pRelativePath = (LPWSTR)pImagePath;

    const wchar_t* SystemRootPath = L"\\SystemRoot\\";
    const wchar_t* SystemRootVariablePath = L"%SystemRoot%\\";

    if (_wcsnicmp(pRelativePath,
        SystemRootPath,
        static_cast<int>(wcslen(SystemRootPath))) == 0)
    {
        pRelativePath += wcslen(SystemRootPath);
    }
    else if (_wcsnicmp(pRelativePath,
        SystemRootVariablePath,
        static_cast<int>(wcslen(SystemRootVariablePath))) == 0)
    {
        pRelativePath += wcslen(SystemRootVariablePath);
    }

    //
    // At this point pRelativePath should point to the image path relative to
    // the windows directory.
    //
    WCHAR WindowsPath[MAX_PATH];
    if (!VERIFY_IS_TRUE(GetSystemWindowsDirectoryW(WindowsPath, MAX_PATH)))
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = StringCchPrintfW(DriverFullPath, cchFullPath, L"%s\\%s", WindowsPath, pRelativePath)))
    {
        return hr;
    }

    return hr;
}