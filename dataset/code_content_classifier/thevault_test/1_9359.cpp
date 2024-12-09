HRESULT CSwapAPOSFX::Initialize(UINT32 cbDataSize, BYTE* pbyData)
{
    HRESULT                     hr = S_OK;
    CComPtr<IDeviceTopology>    spMyDeviceTopology;
    CComPtr<IConnector>         spMyConnector;
    GUID                        processingMode;

    IF_TRUE_ACTION_JUMP( ((NULL == pbyData) && (0 != cbDataSize)), hr = E_INVALIDARG, Exit);
    IF_TRUE_ACTION_JUMP( ((NULL != pbyData) && (0 == cbDataSize)), hr = E_INVALIDARG, Exit);

    if (cbDataSize == sizeof(APOInitSystemEffects3))
    {
        APOInitSystemEffects3* papoSysFxInit3 = (APOInitSystemEffects3*)pbyData;

        // Try to get the logging service, but ignore errors as failure to do logging it is not fatal.
        hr = papoSysFxInit3->pServiceProvider->QueryService(SID_AudioProcessingObjectLoggingService, IID_PPV_ARGS(&m_apoLoggingService));
        IF_FAILED_JUMP(hr, Exit);

       // SampleApo supports the new IAudioSystemEffects3 interface so it will receive APOInitSystemEffects3
        // in pbyData if the audio driver has declared support for this.

        // Use IMMDevice to activate IAudioSystemEffectsPropertyStore that contains the default, user and
        // volatile settings.
        IMMDeviceCollection* deviceCollection = reinterpret_cast<APOInitSystemEffects3*>(pbyData)->pDeviceCollection;
        if (deviceCollection != nullptr)
        {
            UINT32 numDevices;
            wil::com_ptr_nothrow<IMMDevice> endpoint;

            // Get the endpoint on which this APO has been created
            // (It is the last device in the device collection)
            if (SUCCEEDED(deviceCollection->GetCount(&numDevices)) && numDevices > 0 &&
                SUCCEEDED(deviceCollection->Item(numDevices - 1, &endpoint)))
            {
                wil::unique_prop_variant activationParam;
                hr = InitPropVariantFromCLSID(SWAP_APO_SFX_CONTEXT, &activationParam);
                IF_FAILED_JUMP(hr, Exit);

                wil::com_ptr_nothrow<IAudioSystemEffectsPropertyStore> effectsPropertyStore;
                hr = endpoint->Activate(__uuidof(effectsPropertyStore), CLSCTX_ALL, &activationParam, effectsPropertyStore.put_void());
                IF_FAILED_JUMP(hr, Exit);

                // This is where an APO might want to open the volatile or default property stores as well 
                // Use STGM_READWRITE if IPropertyStore::SetValue is needed.
                hr = effectsPropertyStore->OpenUserPropertyStore(STGM_READ, m_userStore.put());
                IF_FAILED_JUMP(hr, Exit);
            }
        }

        // Windows should pass a valid collection.
        ATLASSERT(papoSysFxInit2->pDeviceCollection != nullptr);
        IF_TRUE_ACTION_JUMP(papoSysFxInit3->pDeviceCollection == nullptr, hr = E_INVALIDARG, Exit);

        // Get the IDeviceTopology and IConnector interfaces to communicate with this
        // APO's counterpart audio driver. This can be used for any proprietary
        // communication.
        hr = papoSysFxInit3->pDeviceCollection->Item(papoSysFxInit3->nSoftwareIoDeviceInCollection, &m_device);
        IF_FAILED_JUMP(hr, Exit);

        hr = m_device->Activate(__uuidof(IDeviceTopology), CLSCTX_ALL, NULL, (void**)&spMyDeviceTopology);
        IF_FAILED_JUMP(hr, Exit);

        hr = spMyDeviceTopology->GetConnector(papoSysFxInit3->nSoftwareIoConnectorIndex, &spMyConnector);
        IF_FAILED_JUMP(hr, Exit);

        // Save the processing mode being initialized.
        processingMode = papoSysFxInit3->AudioProcessingMode;
    }
    else if (cbDataSize == sizeof(APOInitSystemEffects2))
    {
        //
        // Initialize for mode-specific signal processing
        //
        APOInitSystemEffects2* papoSysFxInit2 = (APOInitSystemEffects2*)pbyData;

        // Save reference to the effects property store. This saves effects settings
        // and is the communication medium between this APO and any associated UI.
        m_spAPOSystemEffectsProperties = papoSysFxInit2->pAPOSystemEffectsProperties;

        // Windows should pass a valid collection.
        ATLASSERT(papoSysFxInit2->pDeviceCollection != nullptr);
        IF_TRUE_ACTION_JUMP(papoSysFxInit2->pDeviceCollection == nullptr, hr = E_INVALIDARG, Exit);

        // Get the IDeviceTopology and IConnector interfaces to communicate with this
        // APO's counterpart audio driver. This can be used for any proprietary
        // communication.
        hr = papoSysFxInit2->pDeviceCollection->Item(papoSysFxInit2->nSoftwareIoDeviceInCollection, &m_device);
        IF_FAILED_JUMP(hr, Exit);

        hr = m_device->Activate(__uuidof(IDeviceTopology), CLSCTX_ALL, NULL, (void**)&spMyDeviceTopology);
        IF_FAILED_JUMP(hr, Exit);

        hr = spMyDeviceTopology->GetConnector(papoSysFxInit2->nSoftwareIoConnectorIndex, &spMyConnector);
        IF_FAILED_JUMP(hr, Exit);

        // Save the processing mode being initialized.
        processingMode = papoSysFxInit2->AudioProcessingMode;

    }
    else if (cbDataSize == sizeof(APOInitSystemEffects))
    {
        //
        // Initialize for default signal processing
        //
        APOInitSystemEffects* papoSysFxInit = (APOInitSystemEffects*)pbyData;

        // Save reference to the effects property store. This saves effects settings
        // and is the communication medium between this APO and any associated UI.
        m_spAPOSystemEffectsProperties = papoSysFxInit->pAPOSystemEffectsProperties;

        // Assume default processing mode
        processingMode = AUDIO_SIGNALPROCESSINGMODE_DEFAULT;
    }
    else
    {
        // Invalid initialization size
        hr = E_INVALIDARG;
        goto Exit;
    }

    // Validate then save the processing mode. Note an endpoint effects APO
    // does not depend on the mode. Windows sets the APOInitSystemEffects2
    // AudioProcessingMode member to GUID_NULL for an endpoint effects APO.
    IF_TRUE_ACTION_JUMP((processingMode != AUDIO_SIGNALPROCESSINGMODE_DEFAULT        &&
                         processingMode != AUDIO_SIGNALPROCESSINGMODE_RAW            &&
                         processingMode != AUDIO_SIGNALPROCESSINGMODE_COMMUNICATIONS &&
                         processingMode != AUDIO_SIGNALPROCESSINGMODE_SPEECH         &&
                         processingMode != AUDIO_SIGNALPROCESSINGMODE_MEDIA          &&
                         processingMode != AUDIO_SIGNALPROCESSINGMODE_MOVIE), hr = E_INVALIDARG, Exit);
    m_AudioProcessingMode = processingMode;

    //
    // An APO that implements signal processing more complex than this sample
    // would configure its processing for the processingMode determined above.
    // If necessary, the APO would also use the IDeviceTopology and IConnector
    // interfaces retrieved above to communicate with its counterpart audio
    // driver to configure any additional signal processing in the driver and
    // associated hardware.
    //

    //
    //  Get the current values
    //
    if (m_userStore != nullptr)
    {
        m_fEnableSwapSFX = GetCurrentEffectsSetting(m_userStore.get(), PKEY_Endpoint_Enable_Channel_Swap_SFX, m_AudioProcessingMode);
    }

    if (m_spAPOSystemEffectsProperties != NULL)
    {
        m_fEnableSwapSFX = GetCurrentEffectsSetting(m_spAPOSystemEffectsProperties, PKEY_Endpoint_Enable_Channel_Swap_SFX, m_AudioProcessingMode);
    }
    
    RtlZeroMemory(m_effectInfos, sizeof(m_effectInfos));
    m_effectInfos[0] = { SwapEffectId, TRUE, m_fEnableSwapSFX ? AUDIO_SYSTEMEFFECT_STATE_ON : AUDIO_SYSTEMEFFECT_STATE_OFF };

    if (cbDataSize != sizeof(APOInitSystemEffects3))
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