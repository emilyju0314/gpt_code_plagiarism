HRESULT CMpegAudEncOutPin::CheckMediaType(const CMediaType *pmtOut)
{
    // Fail if the input pin is not connected.
    if (!m_pFilter->m_pInput->IsConnected()) {
        return VFW_E_NOT_CONNECTED;
    }

    // Reject any media types that we know in advance our 
    // filter cannot use.
    if (pmtOut->majortype != MEDIATYPE_Audio && pmtOut->majortype != MEDIATYPE_Stream) { return S_FALSE; }

    // If SetFormat was previously called, check whether pmtOut exactly 
    // matches the format that was specified in SetFormat.
    // Return S_OK if they match, or VFW_E_INVALIDMEDIATYPE otherwise.)
    if ( m_SetFormat ) {
        if (*pmtOut != m_mt) { return VFW_E_INVALIDMEDIATYPE; }
        else { return S_OK; }
    }

    // Now do the normal check for this media type.
    HRESULT hr;
    hr = m_pFilter->CheckTransform (&m_pFilter->m_pInput->CurrentMediaType(),  // The input type.
                                    pmtOut);                                   // The proposed output type.

    if (hr == S_OK) {
        return S_OK;           // This format is compatible with the current input type.
    }
 
    // This format is not compatible with the current input type. 
    // Maybe we can reconnect the input pin with a new input type.
    
    // Enumerate the upstream filter's preferred output types, and 
    // see if one of them will work.
    CMediaType *pmtEnum;
    BOOL fFound = FALSE;
    IEnumMediaTypes *pEnum;
    hr = m_pFilter->m_pInput->GetConnected()->EnumMediaTypes(&pEnum);
    if (hr != S_OK) {
        return E_FAIL;
    }

    while (hr = pEnum->Next(1, (AM_MEDIA_TYPE **)&pmtEnum, NULL), hr == S_OK)
    {
        // Check this input type against the proposed output type.
        hr = m_pFilter->CheckTransform(pmtEnum, pmtOut);
        if (hr != S_OK) {
            DeleteMediaType(pmtEnum);
            continue; // Try the next one.
        }

        // This input type is a possible candidate. But, we have to make
        // sure that the upstream filter can switch to this type. 
        hr = m_pFilter->m_pInput->GetConnected()->QueryAccept(pmtEnum);
        if (hr != S_OK) {
            // The upstream filter will not switch to this type.
            DeleteMediaType(pmtEnum);
            continue; // Try the next one.
        }
        fFound = TRUE;
        DeleteMediaType(pmtEnum);
        break;
    }
    pEnum->Release();

    if (fFound) {
        // This output type is OK, but if we are asked to use it, we will
        // need to reconnect our input pin. (See SetFormat, below.)
        return S_OK;
    }
    else {
        return VFW_E_INVALIDMEDIATYPE;
    }
}