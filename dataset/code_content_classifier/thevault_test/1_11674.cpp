bool SocketConnecter::connect(const std::string& ip, size_t port)
{
  size_t uport = htons((u_short)port);
  std::string sPort = Conv<size_t>::toString(uport);

  // Resolve the server address and port
  const char* pTemp = ip.c_str();
  iResult = getaddrinfo(pTemp, sPort.c_str(), &hints, &result);  // was DEFAULT_PORT
  if (iResult != 0) {
    Show::write("\n\n  -- getaddrinfo failed with error: " + Conv<int>::toString(iResult));
    return false;
  }

  // Attempt to connect to an address until one succeeds
  for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

    char ipstr[INET6_ADDRSTRLEN];
    void *addr;
    char *ipver;

    // get pointer to address - different fields in IPv4 and IPv6:
    if (ptr->ai_family == AF_INET) { // IPv4
      struct sockaddr_in *ipv4 = (struct sockaddr_in *)ptr->ai_addr;
      addr = &(ipv4->sin_addr);
      ipver = "IPv4";
    }
    else { // IPv6
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ptr->ai_addr;
      addr = &(ipv6->sin6_addr);
      ipver = "IPv6";
    }

    // convert the IP to a string and print it:
    inet_ntop(ptr->ai_family, addr, ipstr, sizeof ipstr);
    //printf("\n  %s: %s", ipver, ipstr);

    // Create a SOCKET for connecting to server
    socket_ = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (socket_ == INVALID_SOCKET) {
      int error = WSAGetLastError();
      Show::write("\n\n  -- socket failed with error: " + Conv<int>::toString(error));
      return false;
    }

    iResult = ::connect(socket_, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
      socket_ = INVALID_SOCKET;
      int error = WSAGetLastError();
      Show::write("\n  WSAGetLastError returned " + Conv<int>::toString(error));
      continue;
    }
    break;
  }

  freeaddrinfo(result);

  if (socket_ == INVALID_SOCKET) {
    int error = WSAGetLastError();
    Show::write("\n\n  -- unable to connect to server, error = " + Conv<int>::toString(error));
    return false;
  }
  return true;
}