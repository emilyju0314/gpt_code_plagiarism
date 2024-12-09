HRESULT CCodeTypeBuilder::GetCallFlags(
        LPCWSTR wszParts,
        CWSDLMessage *pMessage,
        CWSDLPortTypeIO *pIO,
        CWSDLPortTypeOperation *pBindingOp,
        CWSDLBinding *pBinding,
        LPDWORD pdwFlags)
{
    // TODO (jasjitg): support the parts= attribute

//  ATLASSERT( wszParts != NULL );
    ATLASSERT( pMessage != NULL );
    ATLASSERT( pIO != NULL );
    ATLASSERT( pBindingOp != NULL );
    ATLASSERT( pBinding != NULL );
    ATLASSERT( pdwFlags != NULL );

    POSITION pos = pMessage->GetFirstPart();
    CWSDLMessagePart *pPart = NULL;
    if (pos != NULL)
    {
        pPart = pMessage->GetNextPart(pos);
        ATLASSERT( pPart != NULL );
    }

    // REVIEW: ... semantics of message with no parts?
    return GetCallFlags(pMessage, pPart, pIO, pBindingOp, pBinding, pdwFlags);
}