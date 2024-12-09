HRESULT CKWSApoEFX::Initialize(UINT32 cbDataSize, BYTE* pbyData)
{
    HRESULT                     hr = S_OK;
    CComPtr<IMMDevice>	        spMyDevice;
    CComPtr<IDeviceTopology>    spMyDeviceTopology;
    CComPtr<IConnector>         spMyConnector;
    CComPtr<IPart>              spPart;
    UINT                        myPartId;
    CComPtr<IKsControl>         spKsControl;
    ULONG                       cbReturned = 0;
    UINT                        nSoftwareIoConnectorIndex;

    IF_TRUE_ACTION_JUMP( ((NULL == pbyData) && (0 != cbDataSize)), hr = E_INVALIDARG, Exit);
    IF_TRUE_ACTION_JUMP( ((NULL != pbyData) && (0 == cbDataSize)), hr = E_INVALIDARG, Exit);

    if (cbDataSize == sizeof(APOInitSystemEffects3))
    {
        //
        // Initialize for mode-specific signal processing
        //
        APOInitSystemEffects3* papoSysFxInit3 = (APOInitSystemEffects3*)pbyData;

        nSoftwareIoConnectorIndex = papoSysFxInit3->nSoftwareIoConnectorIndex;
             
        // Windows should pass a valid collection.
        ATLASSERT(papoSysFxInit3->pDeviceCollection != nullptr);
        IF_TRUE_ACTION_JUMP(papoSysFxInit3->pDeviceCollection == nullptr, hr = E_INVALIDARG, Exit);

        // Get the IDeviceTopology and IConnector interfaces to communicate with this
        // APO's counterpart audio driver. This can be used for any proprietary
        // communication.
        hr = papoSysFxInit3->pDeviceCollection->Item(papoSysFxInit3->nSoftwareIoDeviceInCollection, &spMyDevice);
        IF_FAILED_JUMP(hr, Exit);       
        
        // Try to get the logging service, but ignore errors as failure to do logging it is not fatal.
        if(SUCCEEDED(papoSysFxInit3->pServiceProvider->QueryService(SID_AudioProcessingObjectLoggingService, IID_PPV_ARGS(&m_apoLoggingService))))
        {
            m_apoLoggingService->ApoLog(APO_LOG_LEVEL_INFO, L"CKWSApoEFX::Initialize called with APOInitSystemEffects3.");
        }        
    }
    else if (cbDataSize == sizeof(APOInitSystemEffects2))
    {
        //
        // Initialize for mode-specific signal processing
        //
        APOInitSystemEffects2* papoSysFxInit2 = (APOInitSystemEffects2*)pbyData;

        nSoftwareIoConnectorIndex = papoSysFxInit2->nSoftwareIoConnectorIndex;
       
        // Save reference to the effects property store. This saves effects settings
        // and is the communication medium between this APO and any associated UI.
        m_spAPOSystemEffectsProperties = papoSysFxInit2->pAPOSystemEffectsProperties;

        // Windows should pass a valid collection.
        ATLASSERT(papoSysFxInit2->pDeviceCollection != nullptr);
        IF_TRUE_ACTION_JUMP(papoSysFxInit2->pDeviceCollection == nullptr, hr = E_INVALIDARG, Exit);

        // Get the IDeviceTopology and IConnector interfaces to communicate with this
        // APO's counterpart audio driver. This can be used for any proprietary
        // communication.
        hr = papoSysFxInit2->pDeviceCollection->Item(papoSysFxInit2->nSoftwareIoDeviceInCollection, &spMyDevice);
        IF_FAILED_JUMP(hr, Exit);

    }
    else
    {
        // Invalid initialization size
        hr = E_INVALIDARG;
        goto Exit;
    }

    hr = spMyDevice->Activate(__uuidof(IKsControl), CLSCTX_ALL, NULL, (void**)&spKsControl);
    IF_FAILED_JUMP(hr, Exit);

    hr = spMyDevice->Activate(__uuidof(IDeviceTopology), CLSCTX_ALL, NULL, (void**)&spMyDeviceTopology);
    IF_FAILED_JUMP(hr, Exit);

    hr = spMyDeviceTopology->GetConnector(nSoftwareIoConnectorIndex, &spMyConnector);
    IF_FAILED_JUMP(hr, Exit);

    spPart = spMyConnector;

    hr = spPart->GetLocalId(&myPartId);
    IF_FAILED_JUMP(hr, Exit);

    KSP_PIN ksPinProperty;
    ::ZeroMemory(&ksPinProperty, sizeof(ksPinProperty));
    ksPinProperty.Property.Set = KSPROPSETID_InterleavedAudio;
    ksPinProperty.Property.Id = KSPROPERTY_INTERLEAVEDAUDIO_FORMATINFORMATION;
    ksPinProperty.Property.Flags = KSPROPERTY_TYPE_GET;
    ksPinProperty.PinId = myPartId & 0x0000ffff;

    ::ZeroMemory(&m_FormatInfo, sizeof(m_FormatInfo));

    hr = spKsControl->KsProperty(&(ksPinProperty.Property), sizeof(ksPinProperty), &m_FormatInfo, sizeof(m_FormatInfo), &cbReturned);
    IF_FAILED_JUMP(hr, Exit);

    IF_TRUE_ACTION_JUMP(m_FormatInfo.Size != sizeof(m_FormatInfo), hr = E_INVALIDARG, Exit);

    if (cbDataSize == sizeof(APOInitSystemEffects3))
    {
        // Register for notification of registry updates in GetApoNotificationRegistrationInfo
    }
    else if (cbDataSize == sizeof(APOInitSystemEffects2))
    {
        //
        //  Register for notification of registry updates
        //
        hr = m_spEnumerator.CoCreateInstance(__uuidof(MMDeviceEnumerator));
        IF_FAILED_JUMP(hr, Exit);

        hr = m_spEnumerator->RegisterEndpointNotificationCallback(this);
        IF_FAILED_JUMP(hr, Exit);

        m_bRegisteredEndpointNotificationCallback = TRUE;
    }

    m_bIsInitialized = true;

Exit:
    return hr;
}