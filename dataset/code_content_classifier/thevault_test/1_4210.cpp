HRESULT CCodeTypeBuilder::ProcessMessage_PAD(
    CWSDLMessage *pMsg,
    CCodeFunction *pCodeFunc,
    DWORD dwFlags,
    DWORD dwCallFlags)
{
    ATLASSERT( pMsg != NULL );
    ATLASSERT( pCodeFunc != NULL );
    ATLASSERT( dwCallFlags & CODEFLAG_PAD );

    bool bType = false;
    POSITION pos = pMsg->GetFirstPart();
    while (pos != NULL)
    {
        if (bType != false)
        {
            EmitFileError(IDS_SDL_PAD_TYPE, pMsg, 0);
            return E_FAIL;
        }

        CWSDLMessagePart *pCheck = pMsg->GetNextPart(pos);
        ATLASSERT( pCheck != NULL );
        if (pCheck->GetTypeName().GetName().GetLength() != 0)
        {
            bType = true;
        }
    }

    HRESULT hr = S_OK;
    if (dwFlags & CODEFLAG_IN)
    {
        // clear the namespace--it should be set from the schema
        pCodeFunc->GetNamespace().Empty();
    }

    if (bType != false)
    {
        // REVIEW (jasjitg): not implemented correctly in atlsoap.h!!!

        // REVIEW (jasjitg): comment/assert below...
        // must have CODEFLAG_CHAIN
        ATLASSERT( dwCallFlags & CODEFLAG_CHAIN );

        // referenced by type= ==> only one message part
        pos = pMsg->GetFirstPart();
        CWSDLMessagePart *pPart = pMsg->GetNextPart(pos);
        ATLASSERT( pPart != NULL );

        hr = ProcessMessagePart_PAD(pPart, pCodeFunc, dwFlags, dwCallFlags);
    }
    else // referenced by element=
    {
        pos = pMsg->GetFirstPart();
        while (pos != NULL)
        {
            CWSDLMessagePart *pPart = pMsg->GetNextPart(pos);
            ATLASSERT( pPart != NULL );

            hr = ProcessMessagePart_PAD(pPart, pCodeFunc, dwFlags, dwCallFlags);

            if (FAILED(hr))
            {
                break;
            }
        }
    }

    if (FAILED(hr))
    {
        EmitErrorHr(E_FAIL);
    }

    return hr;
}