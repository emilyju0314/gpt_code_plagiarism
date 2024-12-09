bool Socket::send(size_t bytes, byte* buffer)
{
  size_t bytesSent = 0, bytesLeft = bytes;
  byte* pBuf = buffer;
  while (bytesLeft > 0)
  {
    bytesSent = ::send(socket_, pBuf, bytesLeft, 0);
    if (socket_ == INVALID_SOCKET || bytesSent == 0)
      return false;
    bytesLeft -= bytesSent;
    pBuf += bytesSent;
  }
  return true;
}