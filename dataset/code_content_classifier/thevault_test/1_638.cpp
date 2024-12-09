void WiFiDatagram::stop()
{
  if (_sock == NO_SOCKET_AVAIL)
    return;

  tm_net_udp_close_socket(_sock);

  _sock = NO_SOCKET_AVAIL;
}