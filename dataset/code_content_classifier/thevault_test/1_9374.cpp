STDMETHODIMP CAecApoMFX::LockForProcess(UINT32 u32NumInputConnections,
    APO_CONNECTION_DESCRIPTOR** ppInputConnections,  
    UINT32 u32NumOutputConnections, APO_CONNECTION_DESCRIPTOR** ppOutputConnections)
{
    ASSERT_NONREALTIME();
    HRESULT hr = S_OK;

    UNCOMPRESSEDAUDIOFORMAT  uncompAudioFormat;

    // fill in the samples per frame for the output (since APO_FLAG_SAMPLESPERFRAME_MUST_MATCH is not selected)
    // There are two potentially different samples per frame values here. The input, which will be interleaved + primary. 
    // And the output, which is just the primary. Because this is used for clearing the zeroing the output buffer, we're going
    // to fill it in with the output samples per frame. ProcessBuffer has both.
    hr = ppOutputConnections[0]->pFormat->GetUncompressedAudioFormat(&uncompAudioFormat);
    IF_FAILED_JUMP(hr, Exit);

    m_u32SamplesPerFrame = uncompAudioFormat.dwSamplesPerFrame;

    hr = CBaseAudioProcessingObject::LockForProcess(u32NumInputConnections,
        ppInputConnections, u32NumOutputConnections, ppOutputConnections);
    IF_FAILED_JUMP(hr, Exit);
    
Exit:
    return hr;
}