STDMETHODIMP CDelayAPOMFX::IsOutputFormatSupported
(
    IAudioMediaType *pInputFormat, 
    IAudioMediaType *pRequestedOutputFormat, 
    IAudioMediaType **ppSupportedOutputFormat
)
{
    ASSERT_NONREALTIME();
    bool formatChanged = false;
    HRESULT hResult;
    UNCOMPRESSEDAUDIOFORMAT uncompOutputFormat;
    IAudioMediaType *recommendedFormat = NULL;

    IF_TRUE_ACTION_JUMP((NULL == pRequestedOutputFormat) || (NULL == ppSupportedOutputFormat), hResult = E_POINTER, Exit);
    *ppSupportedOutputFormat = NULL;

    // Initial comparison to make sure the requested format is valid and consistent with the input
    // format. Because of the APO flags specified during creation, the samples per frame value will
    // not be validated.
    hResult = IsFormatTypeSupported(pInputFormat, pRequestedOutputFormat, &recommendedFormat, true);
    IF_FAILED_JUMP(hResult, Exit);

    // Check to see if a custom format from the APO was used.
    if (S_FALSE == hResult)
    {
        hResult = CheckCustomFormats(pRequestedOutputFormat);

        // If the output format is changed, make sure we track it for our return code.
        if (S_FALSE == hResult)
        {
            formatChanged = true;
        }
    }

    // now retrieve the format that IsFormatTypeSupported decided on, building upon that by adding
    // our channel count constraint.
    hResult = recommendedFormat->GetUncompressedAudioFormat(&uncompOutputFormat);
    IF_FAILED_JUMP(hResult, Exit);

    // If the requested format exactly matched our requirements,
    // just return it.
    if (!formatChanged)
    {
        *ppSupportedOutputFormat = pRequestedOutputFormat;
        (*ppSupportedOutputFormat)->AddRef();
        hResult = S_OK;
    }
    else // we're proposing something different, copy it and return S_FALSE
    {
        hResult = CreateAudioMediaTypeFromUncompressedAudioFormat(&uncompOutputFormat, ppSupportedOutputFormat);
        IF_FAILED_JUMP(hResult, Exit);
        hResult = S_FALSE;
    }

Exit:
    if (recommendedFormat)
    {
        recommendedFormat->Release();
    }

    return hResult;
}