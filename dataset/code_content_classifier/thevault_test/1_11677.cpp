bool SocketListener::bind()
{
  // Resolve the server address and port

  size_t uport = ::htons((u_short)port_);
  std::string sPort = Conv<size_t>::toString(uport);
  iResult = getaddrinfo(NULL, sPort.c_str(), &hints, &result);
  if (iResult != 0) {
    Show::write("\n\n  -- getaddrinfo failed with error: " + Conv<int>::toString(iResult));
    return false;
  }

  // Iterate through all results and bind to first available

  for (auto pResult = result; pResult != NULL; pResult = pResult->ai_next)
  {
    // Create a SOCKET for connecting to server
   
    socket_ = socket(pResult->ai_family, pResult->ai_socktype, pResult->ai_protocol);
    if (socket_ == INVALID_SOCKET) {
      int error = WSAGetLastError();
      Show::write("\n\n  -- socket failed with error: " + Conv<int>::toString(error));
      continue;
    }
    Show::write("\n  server created ListenSocket");

    // Setup the TCP listening socket

    iResult = ::bind(socket_, pResult->ai_addr, (int)pResult->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
      int error = WSAGetLastError();
      Show::write("\n\n  -- bind failed with error: " + Conv<int>::toString(error));
      socket_ = INVALID_SOCKET;
      continue;
    }
    else
    {
      break;
    }
  }
  freeaddrinfo(result);
  return true;
}