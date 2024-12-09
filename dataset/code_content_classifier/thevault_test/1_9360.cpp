HRESULT GetDriverPathViaService
(
    LPWSTR             ServiceName,
    LPWSTR             DriverFullPath,
    UINT               cchFullPath
)
{
    HRESULT                             hr = S_OK;
    wil::unique_schandle                scManager;
    wil::unique_schandle                scService;

    scManager = wil::unique_schandle(OpenSCManagerW(nullptr, nullptr, GENERIC_READ));
    if (!VERIFY_IS_NOT_NULL(scManager.get()))
    {
        hr = E_OUTOFMEMORY;
        return hr;
    }

    scService = wil::unique_schandle(OpenServiceW(scManager.get(), ServiceName, GENERIC_READ));
    if (!VERIFY_IS_NOT_NULL(scService.get()))
    {
        hr = E_OUTOFMEMORY;
        return hr;
    }

    DWORD BytesRequired;
    if (!VERIFY_IS_TRUE(!QueryServiceConfigW(scService.get(), nullptr, 0, &BytesRequired) && ERROR_INSUFFICIENT_BUFFER == GetLastError()))
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        return hr;
    }

    wil::unique_cotaskmem_ptr<BYTE>     pBuff;
    pBuff.reset((BYTE*)CoTaskMemAlloc(BytesRequired));
    if (!VERIFY_IS_NOT_NULL(pBuff))
    {
        hr = E_OUTOFMEMORY;
        return hr;
    }

    LPQUERY_SERVICE_CONFIGW ServiceConfig = (LPQUERY_SERVICE_CONFIGW)pBuff.get();
    DWORD BytesReturned;

    if (!VERIFY_IS_TRUE(QueryServiceConfigW(scService.get(), ServiceConfig, BytesRequired, &BytesReturned)))
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        return hr;
    }

    if (!VERIFY_IS_NOT_NULL(ServiceConfig->lpBinaryPathName))
    {
        hr = E_UNEXPECTED;
        return hr;
    }

    if (!VERIFY_IS_TRUE('\0' != ServiceConfig->lpBinaryPathName[0]))
    {
        hr = E_UNEXPECTED;
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = GetFullPathFromImagePath(ServiceConfig->lpBinaryPathName, DriverFullPath, cchFullPath)))
    {
        return hr;
    }

    return hr;
}