std::pair<native_socket_type, native_socket_type> create_pipe() {
    socklen_t addrlen = sizeof(sockaddr_in);
    native_socket_type socks[2] = {invalid_socket, invalid_socket};
    auto listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == invalid_socket) throw_io_failure("socket() failed");
    union {
        sockaddr_in inaddr;
        sockaddr addr;
    } a;
    memset(&a, 0, sizeof(a));
    a.inaddr.sin_family = AF_INET;
    a.inaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    a.inaddr.sin_port = 0;
    bool success = false;
    // makes sure all sockets are closed in case of an error
    auto guard = detail::make_scope_guard([&] {
        if (success) return; // everyhting's fine
        auto e = WSAGetLastError();
        closesocket(listener);
        closesocket(socks[0]);
        closesocket(socks[1]);
        WSASetLastError(e);
    });
    // bind listener to a local port
    int reuse = 1;
    ccall("setsockopt() failed", ::setsockopt, listener,
          SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char*>(&reuse),
          static_cast<socklen_t>(sizeof(reuse)));
    ccall("bind() failed", ::bind, listener, &a.addr, sizeof(a.inaddr));
    // read the port in use: win32 getsockname may only set the port number
    // (http://msdn.microsoft.com/library/ms738543.aspx):
    memset(&a, 0, sizeof(a));
    ccall("getsockname() failed", ::getsockname, listener, &a.addr, &addrlen);
    a.inaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    a.inaddr.sin_family = AF_INET;
    // set listener to listen mode
    ccall("listen() failed", ::listen, listener, 1);
    // create read-only end of the pipe
    DWORD flags = 0;
    auto read_fd = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, flags);
    if (read_fd == invalid_socket) {
        throw_io_failure("cannot create read handle: WSASocket() failed");
    }
    ccall("connect() failed", ::connect, read_fd, &a.addr, sizeof(a.inaddr));
    // get write-only end of the pipe
    auto write_fd = accept(listener, NULL, NULL);
    if (write_fd == invalid_socket) {
        throw_io_failure("cannot create write handle: accept() failed");
    }
    closesocket(listener);
    success = true;
    return {read_fd, write_fd};
}