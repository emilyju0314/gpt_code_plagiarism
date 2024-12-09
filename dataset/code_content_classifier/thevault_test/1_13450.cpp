const ISocketPtr Factory::getSocket(const sock::Protocol proto)
{
    ISocketPtr sock;
    try
    {
        switch (proto)
        {
        case sock::UNIXDOMAIN:
            sock = ISocketPtr(new DomainSocket());
            break;
        case sock::TCPIP:
            sock = ISocketPtr(new TCPSocket());
            break;
        case sock::UDP:
            sock = ISocketPtr(new UDPConnectSocket());
            break;
        default:
            break;
        }
    }
    catch(const std::bad_alloc&)
    {
        throw Exception(__FILE__, __LINE__, err::MEMORYALLOC);
    }
    BOOST_ASSERT(sock);
    return sock;
}