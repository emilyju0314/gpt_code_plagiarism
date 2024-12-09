void
tcp_socket::create_socket_if_necessary(void) {
  if (m_fd != __TACOPIE_INVALID_FD) { return; }

  //! new TCP socket
  //! handle case of unix sockets by checking whether the port is 0 or not
  //! also handle ipv6 addr
  short family;
  if (m_port == 0) {
    family = AF_UNIX;
  }
  else if (is_ipv6()) {
    family = AF_INET6;
  }
  else {
    family = AF_INET;
  }

  m_fd   = socket(family, SOCK_STREAM, 0);
  m_type = type::UNKNOWN;

  if (m_fd == __TACOPIE_INVALID_FD) { __TACOPIE_THROW(error, "tcp_socket::create_socket_if_necessary: socket() failure"); }
}