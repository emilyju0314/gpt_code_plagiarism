bool SocketListener::listen()
{
  iResult = ::listen(socket_, SOMAXCONN);
  if (iResult == SOCKET_ERROR) {
    int error = WSAGetLastError();
    Show::write("\n\n  -- listen failed with error: " + Conv<int>::toString(error));
    socket_ = INVALID_SOCKET;
    return false;
  }
  Show::write("\n  server TCP listening socket setup complete");
  return true;
}