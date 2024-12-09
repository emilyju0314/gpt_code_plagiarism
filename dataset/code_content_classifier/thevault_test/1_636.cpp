uint8_t WiFiDatagram::begin(uint16_t port)
{
  _sock = tm_net_udp_open_socket();
  if (_sock >= 0 && tm_net_udp_listen(_sock, port) == 0) {
    _port = port;
    return 1;
  }
  _sock = NO_SOCKET_AVAIL;
  return 0;
}