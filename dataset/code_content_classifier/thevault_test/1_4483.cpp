HRESULT CMpegAudEnc::CheckTransform(const CMediaType* mtIn, const CMediaType* mtOut)
{
	if(MEDIATYPE_Stream != mtOut->majortype)
	{
		if (*mtOut->FormatType() != FORMAT_WaveFormatEx)
			return VFW_E_INVALIDMEDIATYPE;

		if (mtOut->FormatLength() < sizeof(WAVEFORMATEX))
			return VFW_E_INVALIDMEDIATYPE;

		MPEG_ENCODER_CONFIG	mec;
		if(FAILED(m_Encoder.GetOutputType(&mec)))
			return S_OK;

		if (((LPWAVEFORMATEX)mtIn->Format())->nSamplesPerSec % mec.dwSampleRate != 0)
			return S_OK;

		if (mec.dwSampleRate != ((LPWAVEFORMATEX)mtOut->Format())->nSamplesPerSec)
			return VFW_E_TYPE_NOT_ACCEPTED;

		return S_OK;
	}
	else if(mtOut->subtype == MEDIASUBTYPE_MPEG1Audio)
		return S_OK;

	return VFW_E_TYPE_NOT_ACCEPTED;
}