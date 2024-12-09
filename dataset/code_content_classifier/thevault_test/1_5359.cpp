ts::SocketErrorCode ts::UDPSocket::receiveOne(void* data, size_t max_size, size_t& ret_size, SocketAddress& sender, SocketAddress& destination, Report& report)
{
    // Clear returned values
    ret_size = 0;
    sender.clear();
    destination.clear();

    // Reserve a socket address to receive the sender address.
    ::sockaddr sender_sock;
    TS_ZERO(sender_sock);

    // Normally, this operation should be done quite easily using recvmsg.
    // On Windows, all socket operations are smoothly emulated, including
    // recvfrom, allowing a reasonable portability. However, in the specific
    // case of recvmsg, there is no equivalent but a similar - and carefully
    // incompatible - function named WSARecvMsg. Not only this function is
    // different from recvmsg, but it is also not exported from any DLL.
    // Its address must be queried dynamically. The stupid idiot who had
    // this pervert idea at Microsoft deserves to burn in hell (twice) !!

#if defined(TS_WINDOWS)

    // First, get the address of WSARecvMsg the first time we use it.
    if (_wsaRevcMsg == 0) {
        ::LPFN_WSARECVMSG funcAddress = 0;
        ::GUID guid = WSAID_WSARECVMSG;
        ::DWORD dwBytes = 0;
        const ::SOCKET sock = ::socket(AF_INET, SOCK_DGRAM, 0);
        if (sock == INVALID_SOCKET) {
            return LastSocketErrorCode();
        }
        if (::WSAIoctl(sock, SIO_GET_EXTENSION_FUNCTION_POINTER, &guid, sizeof(guid), &funcAddress, sizeof(funcAddress), &dwBytes, 0, 0) != 0) {
            const SocketErrorCode err = LastSocketErrorCode();
            ::closesocket(sock);
            return err;
        }
        ::closesocket(sock);
        // Now update the volatile value.
        _wsaRevcMsg = funcAddress;
    }

    // Build an WSABUF pointing to the message.
    ::WSABUF vec;
    TS_ZERO(vec);
    vec.buf = reinterpret_cast<CHAR*>(data);
    vec.len = ::ULONG(max_size);

    // Reserve a buffer to receive packet ancillary data.
    ::CHAR ancil_data[1024];
    TS_ZERO(ancil_data);

    // Build a WSAMSG for WSARecvMsg.
    ::WSAMSG msg;
    TS_ZERO(msg);
    msg.name = &sender_sock;
    msg.namelen = sizeof(sender_sock);
    msg.lpBuffers = &vec;
    msg.dwBufferCount = 1; // number of WSAMSG
    msg.Control.buf = ancil_data;
    msg.Control.len = ::ULONG(sizeof(ancil_data));

    // Wait for a message.
    ::DWORD insize = 0;
    if (_wsaRevcMsg(getSocket(), &msg, &insize, 0, 0)  != 0) {
        return LastSocketErrorCode();
    }

    // Browse returned ancillary data.
    for (::WSACMSGHDR* cmsg = WSA_CMSG_FIRSTHDR(&msg); cmsg != 0; cmsg = WSA_CMSG_NXTHDR(&msg, cmsg)) {
        if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_PKTINFO) {
            const ::IN_PKTINFO* info = reinterpret_cast<const ::IN_PKTINFO*>(WSA_CMSG_DATA(cmsg));
            destination = SocketAddress(info->ipi_addr, _local_address.port());
        }
    }

#else
    // UNIX implementation, use a standard recvmsg sequence.

    // Build an iovec pointing to the message.
    ::iovec vec;
    TS_ZERO(vec);
    vec.iov_base = data;
    vec.iov_len = max_size;

    // Reserve a buffer to receive packet ancillary data.
    uint8_t ancil_data[1024];
    TS_ZERO(ancil_data);

    // Build a msghdr structure for recvmsg().
    ::msghdr hdr;
    TS_ZERO(hdr);
    hdr.msg_name = &sender_sock;
    hdr.msg_namelen = sizeof(sender_sock);
    hdr.msg_iov = &vec;
    hdr.msg_iovlen = 1; // number of iovec structures
    hdr.msg_control = ancil_data;
    hdr.msg_controllen = sizeof(ancil_data);

    // Wait for a message.
    TS_SOCKET_SSIZE_T insize = ::recvmsg(getSocket(), &hdr, 0);

    if (insize < 0) {
        return LastSocketErrorCode();
    }

    // Browse returned ancillary data.
    for (::cmsghdr* cmsg = CMSG_FIRSTHDR(&hdr); cmsg != nullptr; cmsg = CMSG_NXTHDR(&hdr, cmsg)) {
        if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_PKTINFO && cmsg->cmsg_len >= sizeof(::in_pktinfo)) {
            const ::in_pktinfo* info = reinterpret_cast<const ::in_pktinfo*>(CMSG_DATA(cmsg));
            destination = SocketAddress(info->ipi_addr, _local_address.port());
        }
    }

#endif // Windows vs. UNIX

    // Successfully received a message
    ret_size = size_t(insize);
    sender = SocketAddress(sender_sock);

    return SYS_SUCCESS;
}