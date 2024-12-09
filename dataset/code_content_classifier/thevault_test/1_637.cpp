int WiFiDatagram::available()
{
  if (_sock != NO_SOCKET_AVAIL) {
    return tm_net_is_readable(_sock);
  }
  return 0;
}