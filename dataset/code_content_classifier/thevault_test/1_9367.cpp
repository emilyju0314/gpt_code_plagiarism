HRESULT IsMVA
(
    EndpointConnectorType eConnectorType,
    IMMDevice* pDevice,
    bool* pIsMVA
)
{
    HRESULT hr = S_OK;
    wil::com_ptr_nothrow<IMMDevice>             adapterDevice;
    wil::com_ptr_nothrow<IKsControl>            ksControl;
    ULONG                                       ulReturned = 0;
    ULONG                                       propertySupportFlags = 0;
    KSSOUNDDETECTORPROPERTY                     vam2Property = {0};

    if (!VERIFY_IS_TRUE(pDevice != nullptr)) {
        hr = E_FAIL;
        return hr;
    }

    if (!VERIFY_IS_TRUE(pIsMVA != nullptr)) {
        hr = E_FAIL;
        return hr;
    }

    // If it isn't a keyword connector, it's not MVA, we're done.
    if (eConnectorType != eKeywordDetectorConnector)
    {
        *pIsMVA = FALSE;
        return S_OK;
    }

    if (!VERIFY_SUCCEEDED(hr = GetAudioFilterAsDevice(pDevice, &adapterDevice)))
    {
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = adapterDevice->Activate(__uuidof(IKsControl), CLSCTX_ALL, NULL, (VOID**) &ksControl))) {
        return hr;
    }

    // At this point we know that it is a keyword detector connector and we have the required interface to call into the driver
    // to see if it's MVA. If it's not MVA, it's SVA, so mark it as SVA here.
    *pIsMVA = false;

    vam2Property.Property.Set = KSPROPSETID_SoundDetector2;
    vam2Property.Property.Id = KSPROPERTY_SOUNDDETECTOR_SUPPORTEDPATTERNS;
    vam2Property.Property.Flags = KSPROPERTY_TYPE_BASICSUPPORT;
    vam2Property.EventId = GUID_NULL;

    hr = ksControl->KsProperty(
                (PKSPROPERTY)&vam2Property,
                sizeof(vam2Property),
                &propertySupportFlags,
                sizeof(propertySupportFlags),
                &ulReturned);
    if (SUCCEEDED(hr) && 
        propertySupportFlags == (KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_BASICSUPPORT))
    {
        // Success, we've identified this as a connector which supports MVA, mark it.
        *pIsMVA = true;
    }

    return S_OK;
}