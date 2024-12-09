HRESULT CMpegAudEnc::DecideBufferSize(
                        IMemAllocator*		  pAllocator,
                        ALLOCATOR_PROPERTIES* pProperties)
{
    HRESULT hr = S_OK;

	if(m_bStreamOutput)
		m_cbStreamAlignment = pProperties->cbAlign;

    ///
    if (pProperties->cBuffers == 0) pProperties->cBuffers = 1;  // If downstream filter didn't suggest a buffer count then default to 1
    pProperties->cbBuffer = OUT_BUFFER_SIZE;
	//
	
	ASSERT(pProperties->cbBuffer);
	
    ALLOCATOR_PROPERTIES Actual;
    hr = pAllocator->SetProperties(pProperties,&Actual);
    if(FAILED(hr))
        return hr;

    if (Actual.cbBuffer < pProperties->cbBuffer ||
        Actual.cBuffers < pProperties->cBuffers) 
    {// can't use this allocator
        return E_INVALIDARG;
    }
    return S_OK;
}