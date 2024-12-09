STDMETHODIMP CDelayAPOMFX::LockForProcess(UINT32 u32NumInputConnections,
    APO_CONNECTION_DESCRIPTOR** ppInputConnections,  
    UINT32 u32NumOutputConnections, APO_CONNECTION_DESCRIPTOR** ppOutputConnections)
{
    ASSERT_NONREALTIME();
    HRESULT hr = S_OK;
    
    hr = CBaseAudioProcessingObject::LockForProcess(u32NumInputConnections,
        ppInputConnections, u32NumOutputConnections, ppOutputConnections);
    IF_FAILED_JUMP(hr, Exit);
    
    if (!IsEqualGUID(m_AudioProcessingMode, AUDIO_SIGNALPROCESSINGMODE_RAW) && m_fEnableDelayMFX)
    {
        m_nDelayFrames = FRAMES_FROM_HNS(HNS_DELAY);
        m_iDelayIndex = 0;

        m_pf32DelayBuffer.Free();

        // Allocate one second's worth of audio
        // 
        // This allocation is being done using CoTaskMemAlloc because the delay is very large
        // This introduces a risk of glitches if the delay buffer gets paged out
        //
        // A more typical approach would be to allocate the memory using AERT_Allocate, which locks the memory
        // But for the purposes of this APO, CoTaskMemAlloc suffices, and the risk of glitches is not important
        m_pf32DelayBuffer.Allocate(GetSamplesPerFrame() * m_nDelayFrames);
        WriteSilence(m_pf32DelayBuffer, m_nDelayFrames, GetSamplesPerFrame());
        if (nullptr == m_pf32DelayBuffer)
        {
            hr = E_OUTOFMEMORY;
            goto Exit;
        }
    }
    
Exit:
    return hr;
}