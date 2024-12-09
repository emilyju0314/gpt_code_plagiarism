HRESULT IsSideband
(
    IMMDevice* pDevice,
    bool* pIsSideband
)
{
    HRESULT                                 hr = S_OK;
    wil::com_ptr_nothrow<IPropertyStore>    spPropertyStore;
    wil::unique_prop_variant                varIsSideband;

    *pIsSideband = false;

    // Open pnp device property store
    if (!VERIFY_SUCCEEDED(hr = pDevice->OpenPropertyStore(STGM_READ, &spPropertyStore))) {
        return hr;
    }

    // Read the PKEY_Endpoint_IsBluetooth
    hr = spPropertyStore->GetValue((REFPROPERTYKEY)PKEY_Endpoint_IsSideband, &varIsSideband);
    if (hr != S_OK) {
        return hr;
    }

    if (varIsSideband.vt == VT_BOOL)
    {
        *pIsSideband = varIsSideband.boolVal == VARIANT_TRUE ? true : false;
    }

    return hr;
}