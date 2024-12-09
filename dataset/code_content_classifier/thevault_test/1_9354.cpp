HRESULT CDelayAPOMFX::ValidateAndCacheConnectionInfo(UINT32 u32NumInputConnections,
                APO_CONNECTION_DESCRIPTOR** ppInputConnections,
                UINT32 u32NumOutputConnections,
                APO_CONNECTION_DESCRIPTOR** ppOutputConnections)
{
    ASSERT_NONREALTIME();
    HRESULT hResult;
    CComPtr<IAudioMediaType> pFormat;
    UNCOMPRESSEDAUDIOFORMAT UncompInputFormat, UncompOutputFormat;
    FLOAT32 f32InverseChannelCount;

    UNREFERENCED_PARAMETER(u32NumInputConnections);
    UNREFERENCED_PARAMETER(u32NumOutputConnections);

    _ASSERTE(!m_bIsLocked);
    _ASSERTE(((0 == u32NumInputConnections) || (NULL != ppInputConnections)) &&
              ((0 == u32NumOutputConnections) || (NULL != ppOutputConnections)));

    EnterCriticalSection(&m_CritSec);

    // get the uncompressed formats and channel masks
    hResult = ppInputConnections[0]->pFormat->GetUncompressedAudioFormat(&UncompInputFormat);
    IF_FAILED_JUMP(hResult, Exit);
    
    hResult = ppOutputConnections[0]->pFormat->GetUncompressedAudioFormat(&UncompOutputFormat);
    IF_FAILED_JUMP(hResult, Exit);

    // Since we haven't overridden the IsIn{Out}putFormatSupported APIs in this example, this APO should
    // always have input channel count == output channel count.  The sampling rates should also be eqaul,
    // and formats 32-bit float.
    _ASSERTE(UncompOutputFormat.fFramesPerSecond == UncompInputFormat.fFramesPerSecond);
    _ASSERTE(UncompOutputFormat. dwSamplesPerFrame == UncompInputFormat.dwSamplesPerFrame);

    // Allocate some locked memory.  We will use these as scaling coefficients during APOProcess->ProcessDelayScale
    hResult = AERT_Allocate(sizeof(FLOAT32)*m_u32SamplesPerFrame, (void**)&m_pf32Coefficients);
    IF_FAILED_JUMP(hResult, Exit);

    // Set scalars to decrease volume from 1.0 to 1.0/N where N is the number of channels
    // starting with the first channel.
    f32InverseChannelCount = 1.0f/m_u32SamplesPerFrame;
    for (UINT32 u32Index=0; u32Index<m_u32SamplesPerFrame; u32Index++)
    {
        m_pf32Coefficients[u32Index] = 1.0f - (FLOAT32)(f32InverseChannelCount)*u32Index;
    }

    
Exit:
    LeaveCriticalSection(&m_CritSec);
    return hResult;}