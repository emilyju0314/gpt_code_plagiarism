HRESULT CMpegAudEnc::CheckInputType(const CMediaType* mtIn)
{
    if (*mtIn->Type() == MEDIATYPE_Audio && *mtIn->FormatType() == FORMAT_WaveFormatEx)
        if (mtIn->FormatLength() >= sizeof(WAVEFORMATEX))
            if (mtIn->IsTemporalCompressed() == FALSE)
                return m_Encoder.SetInputType((LPWAVEFORMATEX)mtIn->Format(), true);

    return E_INVALIDARG;
}