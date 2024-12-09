HRESULT IsPortCls
(
    IMMDevice*          pDevice,
    bool*               pIsPortCls
)
{
    HRESULT                                 hr = S_OK;
    wil::com_ptr_nothrow<IMMDevice>         spDevnodeDevice;
    wil::com_ptr_nothrow<IPropertyStore>    spPnpProperties;
    wil::unique_prop_variant                varDeviceService;

    *pIsPortCls = false;

    // Find the associated PnP device 
    if (!VERIFY_SUCCEEDED(hr = GetPnpDevnodeFromMMDevice(pDevice, &spDevnodeDevice))) {
        return hr;
    }

    // Open pnp device property store
    if (!VERIFY_SUCCEEDED(hr = spDevnodeDevice->OpenPropertyStore(STGM_READ, &spPnpProperties))) {
        return hr;
    }

    // Read the DEVPKEY_Device_Service
    if (!VERIFY_SUCCEEDED(hr = spPnpProperties->GetValue((REFPROPERTYKEY)DEVPKEY_Device_Service, &varDeviceService))) {
        return hr;
    }

    // If DEVPKEY_Device_Service is empty, it likely means a raw PDO, which means the device is handled by the parent FDO.
    // For practical purposes, this would most likely mean a non-PortCls pin, which is what we were trying to determine, so it is OK.
    if (varDeviceService.vt == VT_EMPTY) {
        return S_OK;
    }

    if (!VERIFY_IS_TRUE(varDeviceService.vt == VT_LPWSTR && varDeviceService.pwszVal != nullptr)) {
        hr = E_FAIL;
        return hr;
    }

    WCHAR FullPath[MAX_PATH];
    if (!VERIFY_SUCCEEDED(hr = GetDriverPathViaService(varDeviceService.pwszVal, FullPath, MAX_PATH))) {
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = CheckImports(FullPath, "portcls.sys", "PcNewPort", pIsPortCls))) {
        return hr;
    }

    return hr;
}