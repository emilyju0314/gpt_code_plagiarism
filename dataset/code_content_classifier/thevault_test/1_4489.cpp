HRESULT CMpegAudEncOutPin::GetMediaType(int iPosition, CMediaType *pmt)
{
    if (iPosition < 0) return E_INVALIDARG;

    // If iPosition equals zero then we always return the currently configured MediaType 
    if (iPosition == 0) {
        *pmt = m_mt;
        return S_OK;
    }

    switch (iPosition)
    {
        case 1:
        {
            pmt->SetType(&MEDIATYPE_Audio);
            pmt->SetSubtype(&MEDIASUBTYPE_MP3);
            break;
        }
        case 2:
        {
            pmt->SetType(&MEDIATYPE_Stream);
            pmt->SetSubtype(&MEDIASUBTYPE_MPEG1Audio);
            pmt->SetFormatType(&GUID_NULL);
            break;
        }
        case 3:
        {   // The last case that we evaluate is the MPEG2_PES format, but if the 
            // encoder isn't configured for it then just return VFW_S_NO_MORE_ITEMS
            if ( !m_pFilter->m_Encoder.IsPES() ) { return VFW_S_NO_MORE_ITEMS; }

            pmt->SetType(&MEDIATYPE_MPEG2_PES);
            pmt->SetSubtype(&MEDIASUBTYPE_MPEG2_AUDIO);
            break;
        }
        default:
            return VFW_S_NO_MORE_ITEMS;
    }


    // Output capabilities are dependent on the input so insure it is connected
    if ( !m_pFilter->m_pInput->IsConnected() ) {
        pmt->SetFormatType(&FORMAT_None);
        return NOERROR;
    }


    // Annotate the current MediaType index for recall in CMpegAudEnc::Reconnect()
    m_pFilter->m_currentMediaTypeIndex = iPosition;

    // Configure the remaining AM_MEDIA_TYPE parameters using the cached encoder settings.
    // Since MEDIATYPE_Stream doesn't have a format block the current settings 
    // for CHANNEL MODE, BITRATE and SAMPLERATE are cached in m_CurrentOutputFormat for use
    // when we setup the LAME encoder in the call to CMpegAudEncOutPin::SetMediaType()
    MPEG_ENCODER_CONFIG mec;
    m_pFilter->m_Encoder.GetOutputType(&mec);           // Retrieve the current encoder config

    WAVEFORMATEX wf;                                    // Retrieve the input configuration
    m_pFilter->m_Encoder.GetInputType(&wf);

    // Use the current encoder sample rate unless it isn't a modulus of the input rate
    if ((wf.nSamplesPerSec % mec.dwSampleRate) == 0) { 
        m_CurrentOutputFormat.nSampleRate = mec.dwSampleRate;
    }
    else {
        m_CurrentOutputFormat.nSampleRate = wf.nSamplesPerSec;
    }

    // Select the output channel config based on the encoder config and input channel count
    m_CurrentOutputFormat.ChMode = mec.ChMode;
    switch (wf.nChannels)                    // Determine if we need to alter ChMode based upon the channel count and ForceMono flag 
    {
        case 1:
        {
            m_CurrentOutputFormat.ChMode = MONO;
            break;
        }
        case 2:
        {
            if (mec.ChMode == MONO && !mec.bForceMono) { m_CurrentOutputFormat.ChMode = STEREO; }
            else if ( mec.bForceMono ) { m_CurrentOutputFormat.ChMode = MONO; }
            break;
        }
    }

    // Select the encoder bit rate. In VBR mode we set the data rate parameter
    // of the WAVE_FORMAT_MPEGLAYER3 structure to the minimum VBR value
    m_CurrentOutputFormat.nBitRate = (mec.vmVariable == vbr_off) ? mec.dwBitrate : mec.dwVariableMin;

    if (pmt->majortype == MEDIATYPE_Stream) return NOERROR;     // No further config required for MEDIATYPE_Stream


    // Now configure the remainder of the WAVE_FORMAT_MPEGLAYER3 format block
    // and its parent AM_MEDIA_TYPE structure
    DECLARE_PTR(MPEGLAYER3WAVEFORMAT, p_mp3wvfmt, pmt->AllocFormatBuffer(sizeof(MPEGLAYER3WAVEFORMAT)));
    ZeroMemory(p_mp3wvfmt, sizeof(MPEGLAYER3WAVEFORMAT));

    p_mp3wvfmt->wfx.wFormatTag = WAVE_FORMAT_MPEGLAYER3;
    p_mp3wvfmt->wfx.nChannels = (m_CurrentOutputFormat.ChMode == MONO) ? 1 : 2;
    p_mp3wvfmt->wfx.nSamplesPerSec = m_CurrentOutputFormat.nSampleRate;
    p_mp3wvfmt->wfx.nAvgBytesPerSec = GET_DATARATE(m_CurrentOutputFormat.nBitRate);
    p_mp3wvfmt->wfx.nBlockAlign = 1;
    p_mp3wvfmt->wfx.wBitsPerSample = 0;
    p_mp3wvfmt->wfx.cbSize = sizeof(MPEGLAYER3WAVEFORMAT) - sizeof(WAVEFORMATEX);

    p_mp3wvfmt->wID = MPEGLAYER3_ID_MPEG;
    p_mp3wvfmt->fdwFlags = MPEGLAYER3_FLAG_PADDING_ISO;
    p_mp3wvfmt->nBlockSize = GET_FRAMELENGTH(m_CurrentOutputFormat.nBitRate, p_mp3wvfmt->wfx.nSamplesPerSec);
    p_mp3wvfmt->nFramesPerBlock = 1;
    p_mp3wvfmt->nCodecDelay = 0;

    pmt->SetTemporalCompression(FALSE);
    pmt->SetSampleSize(OUT_BUFFER_SIZE);
    pmt->SetFormat((LPBYTE)p_mp3wvfmt, sizeof(MPEGLAYER3WAVEFORMAT));
    pmt->SetFormatType(&FORMAT_WaveFormatEx);

    return NOERROR;
}