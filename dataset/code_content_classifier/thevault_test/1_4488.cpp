HRESULT CMpegAudEncOutPin::SetMediaType(const CMediaType *pmt)
{
    // Retrieve the current LAME encoder configuration
    MPEG_ENCODER_CONFIG mec;
    m_pFilter->m_Encoder.GetOutputType(&mec);

    // Annotate if we are using the MEDIATYPE_Stream output type
    m_pFilter->m_bStreamOutput = (pmt->majortype == MEDIATYPE_Stream);

    if (pmt->majortype == MEDIATYPE_Stream) {
        // Update the encoder configuration using the settings that were
        // cached in the CMpegAudEncOutPin::GetMediaType() call
        mec.dwSampleRate = m_CurrentOutputFormat.nSampleRate;
        mec.dwBitrate = m_CurrentOutputFormat.nBitRate;
        mec.ChMode = m_CurrentOutputFormat.ChMode;
    }
    else {
        // Update the encoder configuration directly using the values
        // passed via the CMediaType structure.  
        MPEGLAYER3WAVEFORMAT *pfmt = (MPEGLAYER3WAVEFORMAT*) pmt->Format();
        mec.dwSampleRate = pfmt->wfx.nSamplesPerSec;
        mec.dwBitrate = pfmt->wfx.nAvgBytesPerSec * 8 / 1000;

        if (pfmt->wfx.nChannels == 1) { mec.ChMode = MONO; }
        else if (pfmt->wfx.nChannels == 2 && mec.ChMode == MONO && !mec.bForceMono) { mec.ChMode = STEREO; }
    }
    m_pFilter->m_Encoder.SetOutputType(mec);

    // Now configure this MediaType on the output pin
    HRESULT hr = CTransformOutputPin::SetMediaType(pmt);
    return hr;
}