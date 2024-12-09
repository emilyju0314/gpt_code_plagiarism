void mg_set_close_on_exec(sock_t sock) {
#ifdef _WIN32
    (void) SetHandleInformation((HANDLE) sock, HANDLE_FLAG_INHERIT, 0);
#else
    fcntl(sock, F_SETFD, FD_CLOEXEC);
#endif
}