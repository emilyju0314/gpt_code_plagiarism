bool ts::UDPSocket::setTOS(int tos, Report& report)
{
    TS_SOCKET_TOS_T utos = TS_SOCKET_TOS_T(tos);
    if (::setsockopt(getSocket(), IPPROTO_IP, IP_TOS, TS_SOCKOPT_T(&utos), sizeof(utos)) != 0) {
        report.error(u"socket option TOS: " + SocketErrorCodeMessage());
        return false;
    }
    return true;
}