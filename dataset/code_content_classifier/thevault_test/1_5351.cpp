bool ts::UDPSocket::setOutgoingMulticast(const UString& name, Report& report)
{
    IPAddress addr;
    return addr.resolve(name, report) && setOutgoingMulticast(addr, report);
}