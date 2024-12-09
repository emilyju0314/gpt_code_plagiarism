HRESULT CMpegAudEnc::GetMediaType(int iPosition, CMediaType *pMediaType)
{
    DbgLog((LOG_TRACE,1,TEXT("CMpegAudEnc::GetMediaType()")));

    return m_pOutput->GetMediaType(iPosition, pMediaType);
}