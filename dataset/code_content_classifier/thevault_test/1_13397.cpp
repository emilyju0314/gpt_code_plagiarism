void RouteAddCommand::checkProtocol(const std::string& protocol)
{
    if (protocol == TCPIP_NAME && m_proto == UDP)
    {
        throw Exception(__FILE__, __LINE__,
                             "Only %s protocol is allowed for the host",
                             UDP_NAME.c_str());
    }

    if (protocol == TCPIP_NAME)
    {
        m_proto = TCPIP;
    }
    else if (protocol == UDP_NAME)
    {
        m_proto = UDP;
    }
    else
    {
        throw Exception(
            __FILE__, __LINE__,
            "Unsupported network protocol '%s'. Possuble values: %s, %s",
            protocol.c_str(),
            TCPIP_NAME.c_str(), UDP_NAME.c_str());
    }
}