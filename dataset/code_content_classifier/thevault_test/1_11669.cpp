bool Socket::sendString(const std::string& str, byte terminator)
{
	size_t bytesSent;
	size_t bytesRemaining = str.size();
  const byte* pBuf = &(*str.begin());
  while (bytesRemaining > 0)
  {
    bytesSent = ::send(socket_, pBuf, bytesRemaining, 0);
    if (bytesSent == INVALID_SOCKET || bytesSent == 0)
      return false;
    bytesRemaining -= bytesSent;
    pBuf += bytesSent;
  }
  ::send(socket_, &terminator, 1, 0);
  return true;
}