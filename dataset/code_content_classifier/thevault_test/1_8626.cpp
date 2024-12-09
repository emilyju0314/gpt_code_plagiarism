static void check_socket_error(Socket socket)
{
  int error = 0;
  socklen_t error_length = sizeof(error);

  if (::getsockopt(socket, SOL_SOCKET, SO_ERROR, (char *)&error, &error_length) != 0)
    throw_socket_error();

  if (error)
#ifdef _WIN32
    throw_error(error, winsock_error_category());
#else

    // Note: this is not very clear in POSIX docs, but the error code returned by
    // getsockopt(.. SO_ERROR ..) should be interpreted like errno value.
    // For example IBM docs for SO_ERROR specify:
    // "Return any pending errors in the socket. The value returned corresponds
    //  to the standard error codes defined in <errno.h>"

    throw_error(error, posix_error_category());
#endif
}