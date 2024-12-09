SVNetwork::SVNetwork(const char *hostname, int port) {
  msg_buffer_in_ = new char[kMaxMsgSize + 1];
  msg_buffer_in_[0] = '\0';

  buffer_ptr_ = nullptr;

  struct addrinfo *addr_info = nullptr;
  auto port_string = std::to_string(port);
#  ifdef _WIN32
  // Initialize Winsock
  WSADATA wsaData;
  int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (iResult != 0) {
    std::cerr << "WSAStartup failed: " << iResult << std::endl;
  }
#  endif // _WIN32

  if (getaddrinfo(hostname, port_string.c_str(), nullptr, &addr_info) != 0) {
    std::cerr << "Error resolving name for ScrollView host "
              << std::string(hostname) << ":" << port << std::endl;
#  ifdef _WIN32
    WSACleanup();
#  endif // _WIN32
  }

  stream_ = socket(addr_info->ai_family, addr_info->ai_socktype,
                   addr_info->ai_protocol);

  if (stream_ < 0) {
    std::cerr << "Failed to open socket" << std::endl;
  } else if (connect(stream_, addr_info->ai_addr, addr_info->ai_addrlen) < 0) {
    // If server is not there, we will start a new server as local child
    // process.
    const char *scrollview_path = getenv("SCROLLVIEW_PATH");
    if (scrollview_path == nullptr) {
#  ifdef SCROLLVIEW_PATH
#    define _STR(a) #    a
#    define _XSTR(a) _STR(a)
      scrollview_path = _XSTR(SCROLLVIEW_PATH);
#    undef _XSTR
#    undef _STR
#  else
      scrollview_path = ".";
#  endif
    }
    const char *prog = ScrollViewProg();
    std::string command = ScrollViewCommand(scrollview_path);
    SVSync::StartProcess(prog, command.c_str());

    // Wait for server to show up.
    // Note: There is no exception handling in case the server never turns up.

    Close();
    for (;;) {
      stream_ = socket(addr_info->ai_family, addr_info->ai_socktype,
                       addr_info->ai_protocol);
      if (stream_ >= 0) {
        if (connect(stream_, addr_info->ai_addr, addr_info->ai_addrlen) == 0) {
          break;
        }

        Close();

        std::cout << "ScrollView: Waiting for server...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    }
  }
#  ifdef _WIN32
  // WSACleanup();  // This cause ScrollView windows is not displayed
#  endif // _WIN32
  freeaddrinfo(addr_info);
}