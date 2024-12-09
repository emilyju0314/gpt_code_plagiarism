HRESULT
CHalfApp::GetSecondHalfApp
(
    AUDIO_SIGNALPROCESSINGMODE secondMode,
    CHalfApp** ppSecondHalfApp
)
{
    HRESULT                                     hr = S_OK;
    ULONG                                       cFormatRecords = 0;
    CComHeapPtr<FORMAT_RECORD>                  spFormatRecords;
    wil::unique_cotaskmem_ptr<WAVEFORMATEX>     pPreferredFormat;
    UINT32                                      u32DefaultPeriodicityInFrames;
    UINT32                                      u32FundamentalPeriodicityInFrames;
    UINT32                                      u32MinPeriodicityInFrames;
    UINT32                                      u32MaxPeriodicityInFrames;
    UINT32                                      u32MaxPeriodicityInFramesExtended;
    DeviceDescriptor                            descriptor = { 0 };

    if (!VERIFY_SUCCEEDED(hr = GetSupportedFormatRecordsForConnector(m_pDevice.get(), m_uConnectorId, m_ConnectorType, secondMode, m_DataFlow, &cFormatRecords, &spFormatRecords))) {
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = GetPreferredFormatForConnector(m_pDevice.get(), m_uConnectorId, m_ConnectorType, secondMode, wil::out_param(pPreferredFormat)))) {
        return hr;
    }

    if (!VERIFY_SUCCEEDED(hr = GetPreferredFormatPeriodicityCharacteristicsForConnector(m_pDevice.get(), m_ConnectorType, secondMode, m_DataFlow, pPreferredFormat.get(), cFormatRecords, spFormatRecords, &u32DefaultPeriodicityInFrames, &u32FundamentalPeriodicityInFrames, &u32MinPeriodicityInFrames, &u32MaxPeriodicityInFrames, &u32MaxPeriodicityInFramesExtended))) {
        return hr;
    }

    descriptor.pDevice = m_pDevice.get();
    descriptor.pwstrAudioEndpointId = m_pwstrDeviceId.get();
    descriptor.pwstrAudioEndpointFriendlyName = m_pwstrDeviceFriendlyName.get();
    descriptor.dataFlow = m_DataFlow;
    descriptor.eConnectorType = m_ConnectorType;
    descriptor.uConnectorId = m_uConnectorId;
    descriptor.mode = secondMode;
    descriptor.cModes = m_cModes;
    descriptor.pModes = m_pModes;
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
    *ppSecondHalfApp = new CHalfApp(descriptor);
    if (*ppSecondHalfApp == NULL) {
        hr = E_OUTOFMEMORY;
        return hr;
    }

    return hr;
}