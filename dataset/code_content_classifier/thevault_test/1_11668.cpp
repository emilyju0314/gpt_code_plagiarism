bool Socket::recv(size_t bytes, byte* buffer)
{
  size_t bytesRecvd = 0, bytesLeft = bytes;
  byte* pBuf = buffer;
  while (bytesLeft > 0)
  {
    bytesRecvd = ::recv(socket_, pBuf, bytesLeft, 0);
    if (socket_ == INVALID_SOCKET || bytesRecvd == 0)
      return false;
    bytesLeft -= bytesRecvd;
    pBuf += bytesRecvd;
  }
  return true;
}