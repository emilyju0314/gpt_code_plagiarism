Socket SocketListener::accept()
{
  ::SOCKET sock = ::accept(socket_, NULL, NULL);
  Socket clientSocket = sock;    // uses Socket(::SOCKET) promotion ctor
  if (!clientSocket.validState()) {
    acceptFailed_ = true;
    int error = WSAGetLastError();
    Show::write("\n\n  -- server accept failed with error: " + Conv<int>::toString(error));
    Show::write(
      "\n  -- this occurs when application shuts down while listener thread is blocked on Accept call"
    );
    return clientSocket;
  }
  return clientSocket;
}