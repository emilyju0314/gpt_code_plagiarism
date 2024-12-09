SipVia::SipVia( const Data& data, const string& local_ip)
    : SipHeader(local_ip),
    host(),
    port(DEFAULT_SIP_PORT),
    protocolName(DEFAULT_PROTOCOL),
    protocolVersion(DEFAULT_VERSION),
    transport(DEFAULT_TRANSPORT),
    viaBranch(false),
    viaComment(false),
    viaReceived(false),
    viaHidden(false),
    viaTtl(false),
    viaMaddr(false),
    rport(false)
{

    if (data == "") {
        return;
    }

    try
    {
        decode(data);
    }
    catch (SipViaParserException&)
    {
        if (SipParserMode::sipParserMode())
        {
	    throw SipViaParserException(
                "failed to decode the Via string",
                __FILE__,
                __LINE__,DECODE_VIA_FAILED);
        }
    }
}