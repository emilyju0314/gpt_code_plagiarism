SocketListener::SocketListener(size_t port, IpVer ipv) : Socket(ipv), port_(port)
{
  socket_ = INVALID_SOCKET;
  ZeroMemory(&hints, sizeof(hints));
  if (ipv == Socket::IP6)
    hints.ai_family = AF_INET6;       // use this if you want an IP6 address
  else
    hints.ai_family = AF_INET;        // this gives IP4 address
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = AI_PASSIVE;
}