std::string Socket::recvString(byte terminator)
{
  static const int buflen = 1;
  char buffer[1];
  std::string str;
  while (true)
  {
    iResult = ::recv(socket_, buffer, buflen, 0);
    if (iResult == 0 || iResult == INVALID_SOCKET)
      break;
    if (buffer[0] == terminator)
      break;
    str += buffer[0];
  }
  return str;
}