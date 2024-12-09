HRESULT GetPnpDevnodeFromMMDevice
(
    IMMDevice* pDevice,
    IMMDevice** pDevnodeDevice
)
{
    HRESULT                                     hr = S_OK;
    wil::com_ptr_nothrow<IMMDeviceEnumerator>   spEnumerator;
    wil::com_ptr_nothrow<IPropertyStore>        spProps;
    wil::com_ptr_nothrow<IMMDevice>             spDevnodeAsDevice;
    wil::com_ptr_nothrow<IPropertyStore>        spDevnodeProps;
    wil::unique_prop_variant                    varDevnode;

    // Create an enumerator
    if (!VERIFY_SUCCEEDED(hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void **)&spEnumerator))) {
        return hr;
    }

    // Read the PKEY_Endpoint_Devnode
    if (!VERIFY_SUCCEEDED(hr = pDevice->OpenPropertyStore(STGM_READ, &spProps))) {
        return hr;
    }
    if (!VERIFY_SUCCEEDED(hr = spProps->GetValue(PKEY_Endpoint_Devnode, &varDevnode))) {
        return hr;
    }

    // Get the devnode as an IMMDevice
    if (!VERIFY_SUCCEEDED(hr = spEnumerator->GetDevice(varDevnode.pwszVal, &spDevnodeAsDevice))) {
        return hr;
    }
    *pDevnodeDevice = spDevnodeAsDevice.detach();

    return hr;
}