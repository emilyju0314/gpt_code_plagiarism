HRESULT
CHalfApp::GetHostHalfApp
(
    CHalfApp** ppHostHalfApp
)
{
    HRESULT                                     hr = S_OK;
    bool                                        bHasConnector = false;
    UINT                                        uConnectorId;
    ULONG                                       cModes = 0;
    CComHeapPtr<AUDIO_SIGNALPROCESSINGMODE>     spModes;
    bool                                        bRawSupport = false;
    bool                                        bDefaultSupport = false;
    AUDIO_SIGNALPROCESSINGMODE                  mode;
    ULONG                                       cFormatRecords = 0;
    CComHeapPtr<FORMAT_RECORD>                  spFormatRecords;
    wil::unique_cotaskmem_ptr<WAVEFORMATEX>     pPreferredFormat;
    UINT32                                      u32DefaultPeriodicityInFrames;
    UINT32                                      u32FundamentalPeriodicityInFrames;
    UINT32                                      u32MinPeriodicityInFrames;
    UINT32                                      u32MaxPeriodicityInFrames;
    UINT32                                      u32MaxPeriodicityInFramesExtended;
    DeviceDescriptor                            descriptor = { 0 };

    // It is only used when testing on loopback pin. When preparing loopback pin, we also need prepare the host pin.
    VERIFY_IS_TRUE(m_ConnectorType == eLoopbackConnector);

    // Get host connector id
    if (!VERIFY_SUCCEEDED(hr = GetConnectorId(m_pDevice.get(), eHostProcessConnector, &bHasConnector, &uConnectorId))) {
        return hr;
    }
    if (!bHasConnector) {
        return hr;
    }

    // Get all signal processing modes for host connector
    if (!VERIFY_SUCCEEDED(hr = GetProcessingModesForConnector(m_pDevice.get(), uConnectorId, eHostProcessConnector, &cModes, &spModes))) {
        return hr;
    }

    // It is possible that host pin support multiple processing modes so we pick up one mode. If host pin support default, use default mode. If host pin support raw, use raw mode.
    for (ULONG i = 0; i < cModes; i++) {
        if (spModes[i] == AUDIO_SIGNALPROCESSINGMODE_RAW)
            bRawSupport = true;
        if (spModes[i] == AUDIO_SIGNALPROCESSINGMODE_DEFAULT)
            bDefaultSupport = true;
    }
    if (!VERIFY_IS_TRUE(bRawSupport || bDefaultSupport)) {
        hr = E_FAIL;
        return hr;
    }
    mode = bDefaultSupport ? AUDIO_SIGNALPROCESSINGMODE_DEFAULT : AUDIO_SIGNALPROCESSINGMODE_RAW;

    if (!VERIFY_SUCCEEDED(hr = GetSupportedFormatRecordsForConnector(m_pDevice.get(), uConnectorId, eHostProcessConnector, mode, render, &cFormatRecords, &spFormatRecords))) {
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = GetPreferredFormatForConnector(m_pDevice.get(), uConnectorId, eHostProcessConnector, mode, wil::out_param(pPreferredFormat)))) {
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = GetPreferredFormatPeriodicityCharacteristicsForConnector(m_pDevice.get(), eHostProcessConnector, mode, render, pPreferredFormat.get(), cFormatRecords, spFormatRecords, &u32DefaultPeriodicityInFrames, &u32FundamentalPeriodicityInFrames, &u32MinPeriodicityInFrames, &u32MaxPeriodicityInFrames, &u32MaxPeriodicityInFramesExtended))) {
        return hr;
    }

    descriptor.pDevice = m_pDevice.get();
    descriptor.pwstrAudioEndpointId = m_pwstrDeviceId.get();
    descriptor.pwstrAudioEndpointFriendlyName = m_pwstrDeviceFriendlyName.get();
    descriptor.dataFlow = render; 
    descriptor.eConnectorType = eHostProcessConnector;
    descriptor.uConnectorId = uConnectorId;
    descriptor.mode = mode;
    descriptor.cModes = cModes;
    descriptor.pModes = spModes;
    descriptor.cFormatRecords = cFormatRecords;
    descriptor.pFormatRecords = spFormatRecords;
    descriptor.pPreferredFormat = pPreferredFormat.get();
    descriptor.u32DefaultPeriodicityInFrames = u32DefaultPeriodicityInFrames;
    descriptor.u32FundamentalPeriodicityInFrames = u32FundamentalPeriodicityInFrames;
    descriptor.u32MinPeriodicityInFrames = u32MinPeriodicityInFrames;
    descriptor.u32MaxPeriodicityInFrames = u32MaxPeriodicityInFrames;
    descriptor.bIsAVStream = m_bIsAVStream;
    descriptor.bIsBluetooth = m_bIsBluetooth;
    descriptor.bIsSideband = m_bIsSideband;
    *ppHostHalfApp = new CHalfApp(descriptor);
    if (*ppHostHalfApp == NULL) {
        hr = E_OUTOFMEMORY;
        return hr;
    }

    return hr;
}