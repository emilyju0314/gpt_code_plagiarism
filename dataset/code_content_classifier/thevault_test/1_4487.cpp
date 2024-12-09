CMpegAudEncOutPin::CMpegAudEncOutPin( CMpegAudEnc * pFilter, HRESULT * pHr ) :
        CTransformOutputPin( NAME("LameEncoderOutputPin"), pFilter, pHr, L"Output\0" ),
        m_pFilter(pFilter)
{
    m_SetFormat = FALSE;
}