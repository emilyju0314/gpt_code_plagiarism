SocketSystem::SocketSystem()
{
  int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (iResult != 0) {
    Show::write("\n  WSAStartup failed with error = " + Conv<int>::toString(iResult));
  }
}