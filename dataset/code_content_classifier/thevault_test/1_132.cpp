otError otNcpStreamWrite(int aStreamId, const uint8_t *aDataPtr, int aDataLen)
{
    otError           error = OT_ERROR_INVALID_STATE;
    ot::Ncp::NcpBase *ncp   = ot::Ncp::NcpBase::GetNcpInstance();

    if (ncp != nullptr)
    {
        error = ncp->StreamWrite(aStreamId, aDataPtr, aDataLen);
    }

    return error;
}