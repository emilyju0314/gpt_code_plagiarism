bool ts::UDPSocket::bind(const SocketAddress& addr, Report& report)
{
    ::sockaddr sock_addr;
    addr.copy(sock_addr);

    report.debug(u"binding socket to %s", {addr});
    if (::bind(getSocket(), &sock_addr, sizeof(sock_addr)) != 0) {
        report.error(u"error binding socket to local address: %s", {SocketErrorCodeMessage()});
        return false;
    }

    // Keep a cached value of the bound local address.
    return getLocalAddress(_local_address, report);
}