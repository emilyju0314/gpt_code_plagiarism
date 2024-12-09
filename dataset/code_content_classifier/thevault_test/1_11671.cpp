size_t Socket::bytesWaiting()
{
  unsigned long int ret;
  ::ioctlsocket(socket_, FIONREAD, &ret);
  return (size_t)ret;
}