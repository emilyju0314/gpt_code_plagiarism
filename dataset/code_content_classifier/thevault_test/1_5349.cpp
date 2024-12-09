bool ts::UDPSocket::open(Report& report)
{
    // Create a datagram socket.
    if (!createSocket(PF_INET, SOCK_DGRAM, IPPROTO_UDP, report)) {
        return false;
    }

    // Set the IP_PKTINFO option. This option is used to get the destination address of all
    // UDP packets arriving on this socket. Actual socket option is an int.
    int opt = 1;
    if (::setsockopt(getSocket(), IPPROTO_IP, IP_PKTINFO, TS_SOCKOPT_T(&opt), sizeof(opt)) != 0) {
        report.error(u"error setting socket IP_PKTINFO option: %s", {SocketErrorCodeMessage()});
        return false;
    }

    return true;
}