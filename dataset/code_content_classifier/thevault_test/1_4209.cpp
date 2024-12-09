HRESULT CCodeTypeBuilder::ProcessMessage_PID(
    CWSDLMessage *pMsg,
    CCodeFunction *pCodeFunc,
    DWORD dwFlags,
    DWORD dwCallFlags)
{
    ATLASSERT( pMsg != NULL );
    ATLASSERT( pCodeFunc != NULL );
    ATLASSERT( dwCallFlags & CODEFLAG_PID );

    // REVIEW (jasjitg): maybe ATLASSERT is too lenient here
    ATLASSERT( pMsg->GetNumParts() == 1 );

    dwCallFlags;

    POSITION pos = pMsg->GetFirstPart();
    if (pos != NULL)
    {
        CWSDLMessagePart *pPart = pMsg->GetNextPart(pos);
        if (pPart != NULL)
        {
            return ProcessMessagePart_PID(pPart, pCodeFunc, dwFlags, dwCallFlags);
        }
    }

    EmitError(IDS_SDL_INTERNAL);
    return E_FAIL;
}