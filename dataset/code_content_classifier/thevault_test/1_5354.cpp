bool ts::UDPSocket::setBroadcast(bool on, Report& report)
{
    int enable = int(on);
    if (::setsockopt(getSocket(), SOL_SOCKET, SO_BROADCAST, TS_SOCKOPT_T(&enable), sizeof(enable)) != 0) {
        report.error(u"socket option broadcast: " + SocketErrorCodeMessage());
        return false;
    }
    return true;
}