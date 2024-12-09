bool ts::SRTSocket::Guts::setDefaultAddress(const ts::UString& name, ts::Report& report)
{
    ts::SocketAddress addr;
    return addr.resolve(name, report) && setDefaultAddress(addr, report);
}