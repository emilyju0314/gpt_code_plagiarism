bool ts::UDPSocket::setDefaultDestination(const UString& name, Report& report)
{
    SocketAddress addr;
    return addr.resolve(name, report) && setDefaultDestination(addr, report);
}