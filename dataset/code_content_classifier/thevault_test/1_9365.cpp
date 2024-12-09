HRESULT IsBluetooth
(
    IMMDevice* pDevice,
    bool* pIsBluetooth
)
{
    HRESULT                                 hr = S_OK;
    wil::com_ptr_nothrow<IPropertyStore>    spPropertyStore;
    wil::unique_prop_variant                varIsBluetooth;

    *pIsBluetooth = false;

    // Open pnp device property store
    if (!VERIFY_SUCCEEDED(hr = pDevice->OpenPropertyStore(STGM_READ, &spPropertyStore))) {
        return hr;
    }

    // Read the PKEY_Endpoint_IsBluetooth
    hr = spPropertyStore->GetValue((REFPROPERTYKEY)PKEY_Endpoint_IsBluetooth, &varIsBluetooth);
    if (hr != S_OK) {
        return hr;
    }

    if (varIsBluetooth.vt == VT_BOOL)
    {
        *pIsBluetooth = varIsBluetooth.boolVal == VARIANT_TRUE ? true : false;
    }

    return hr;
}