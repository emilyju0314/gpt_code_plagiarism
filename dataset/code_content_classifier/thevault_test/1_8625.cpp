static void throw_socket_error()
{
#ifdef _WIN32
  throw_error(WSAGetLastError(), winsock_error_category());
#else
  throw_system_error();
#endif
}