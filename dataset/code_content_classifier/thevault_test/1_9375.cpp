HRESULT CAecApoMFX::Initialize(UINT32 cbDataSize, BYTE* pbyData)
{
    HRESULT                     hr = S_OK;

    IF_TRUE_ACTION_JUMP( ((NULL == pbyData) && (0 != cbDataSize)), hr = E_INVALIDARG, Exit);
    IF_TRUE_ACTION_JUMP( ((NULL != pbyData) && (0 == cbDataSize)), hr = E_INVALIDARG, Exit);

    if (cbDataSize == sizeof(APOInitSystemEffects3))
    {
        //
        // pbyData contains APOInitSystemEffects3 structure describing the microphone endpoint
        //
        APOInitSystemEffects3* papoSysFxInit3 = (APOInitSystemEffects3*)pbyData;
        m_initializedForEffectsDiscovery = papoSysFxInit3->InitializeForDiscoveryOnly;

        // Support for COMMUNICATIONS mode only when streaming
        IF_TRUE_ACTION_JUMP(
            !m_initializedForEffectsDiscovery && (papoSysFxInit3->AudioProcessingMode != AUDIO_SIGNALPROCESSINGMODE_COMMUNICATIONS),
            hr = E_INVALIDARG,
            Exit);
        m_audioSignalProcessingMode = papoSysFxInit3->AudioProcessingMode;

        // Register for notification of endpoint volume change in GetApoNotificationRegistrationInfo      
        // Keep a reference to the device that will be registering for endpoint volume notifcations. 

        IF_TRUE_ACTION_JUMP(papoSysFxInit3->pDeviceCollection == nullptr, hr = E_INVALIDARG, Exit);
        // Get the endpoint on which this APO has been created. It is the last device in the device collection.
        UINT32 numDevices;
        hr = papoSysFxInit3->pDeviceCollection->GetCount(&numDevices);
        IF_FAILED_JUMP(hr, Exit);
        IF_TRUE_ACTION_JUMP(numDevices <= 0, hr = E_INVALIDARG, Exit);

        hr = papoSysFxInit3->pDeviceCollection->Item(numDevices - 1, &m_spCaptureDevice);
        IF_FAILED_JUMP(hr, Exit);

        m_bIsInitialized = true;

        // Try to get the logging service, but ignore errors as failure to do logging it is not fatal.
        if(SUCCEEDED(papoSysFxInit3->pServiceProvider->QueryService(SID_AudioProcessingObjectLoggingService, IID_PPV_ARGS(&m_apoLoggingService))))
        {
            m_apoLoggingService->ApoLog(APO_LOG_LEVEL_INFO, L"CAecApoMFX::Initialize called with APOInitSystemEffects3.");
        }        
    }
    else if (cbDataSize == sizeof(APOInitSystemEffects2))
    {
        //
        // pbyData contains APOInitSystemEffects2 structure describing the microphone endpoint
        //
        APOInitSystemEffects2* papoSysFxInit2 = (APOInitSystemEffects2*)pbyData;
        m_initializedForEffectsDiscovery = papoSysFxInit2->InitializeForDiscoveryOnly;

        // Support for COMMUNICATIONS mode only when streaming
        IF_TRUE_ACTION_JUMP(
            !m_initializedForEffectsDiscovery && (papoSysFxInit2->AudioProcessingMode != AUDIO_SIGNALPROCESSINGMODE_COMMUNICATIONS),
            hr = E_INVALIDARG,
            Exit);
        m_audioSignalProcessingMode = papoSysFxInit2->AudioProcessingMode;

        m_bIsInitialized = true;
    }
    else
    {
        hr = E_INVALIDARG;
    }

Exit:
    return hr;
}