HRESULT CDelayAPOMFX::Initialize(UINT32 cbDataSize, BYTE* pbyData)
{
    HRESULT                     hr = S_OK;
    GUID                        processingMode;

    IF_TRUE_ACTION_JUMP( ((NULL == pbyData) && (0 != cbDataSize)), hr = E_INVALIDARG, Exit);
    IF_TRUE_ACTION_JUMP( ((NULL != pbyData) && (0 == cbDataSize)), hr = E_INVALIDARG, Exit);

    if (cbDataSize == sizeof(APOInitSystemEffects2))
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

        // Save the processing mode being initialized.
        processingMode = papoSysFxInit2->AudioProcessingMode;

        // There is information in the APOInitSystemEffects2 structure that could help facilitate 
        // proprietary communication between an APO instance and the KS pin that the APO is initialized on
        // Eg, in the case that an APO is implemented as an effect proxy for the effect processing hosted inside
        // an driver (either host CPU based or offload DSP based), the example below uses a combination of 
        // IDeviceTopology, IConnector, and IKsControl interfaces to communicate with the underlying audio driver. 
        // the following following routine demonstrates how to implement how to communicate to an audio driver from a APO.
        ProprietaryCommunicationWithDriver(papoSysFxInit2);
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
    //  Get current effects settings
    //
    if (m_spAPOSystemEffectsProperties != NULL)
    {
        m_fEnableDelayMFX = GetCurrentEffectsSetting(m_spAPOSystemEffectsProperties, PKEY_Endpoint_Enable_Delay_MFX, m_AudioProcessingMode);
    }

    //
    //  Register for notification of registry updates
    //
    hr = m_spEnumerator.CoCreateInstance(__uuidof(MMDeviceEnumerator));
    IF_FAILED_JUMP(hr, Exit);

    hr = m_spEnumerator->RegisterEndpointNotificationCallback(this);
    IF_FAILED_JUMP(hr, Exit);

    m_bIsInitialized = true;
Exit:
    return hr;
}