HRESULT CMpegAudEncPropertyPageAdv::OnConnect(IUnknown *pUnknown)
{
    ASSERT(m_pAEProps == NULL);

    // Ask the filter for it's control interface

    HRESULT hr = pUnknown->QueryInterface(IID_IAudioEncoderProperties,(void **)&m_pAEProps);
    if (FAILED(hr) || !m_pAEProps)
        return E_NOINTERFACE;

    ASSERT(m_pAEProps);

    // Get current filter state
//    m_pAEProps->LoadAudioEncoderPropertiesFromRegistry();

    m_pAEProps->get_EnforceVBRmin(&m_dwEnforceVBRmin);
    m_pAEProps->get_VoiceMode(&m_dwVoiceMode);
    m_pAEProps->get_KeepAllFreq(&m_dwKeepAllFreq);
    m_pAEProps->get_StrictISO(&m_dwStrictISO);
    m_pAEProps->get_NoShortBlock(&m_dwNoShortBlock);
    m_pAEProps->get_XingTag(&m_dwXingTag);
    m_pAEProps->get_ChannelMode(&m_dwChannelMode);
    m_pAEProps->get_ForceMS(&m_dwForceMS);
    m_pAEProps->get_ModeFixed(&m_dwModeFixed);
    m_pAEProps->get_SampleOverlap(&m_dwOverlap);
    m_pAEProps->get_SetDuration(&m_dwSetStop);

    return NOERROR;
}