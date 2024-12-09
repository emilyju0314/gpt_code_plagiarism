void
tcp_client::connect(const std::string& host, std::uint32_t port, std::uint32_t timeout_msecs) {
  if (is_connected()) { __TACOPIE_THROW(warn, "tcp_client is already connected"); }

  try {
    m_socket.connect(host, port, timeout_msecs);
    m_io_service->track(m_socket);
  }
  catch (const tacopie_error& e) {
    m_socket.close();
    throw e;
  }

  m_is_connected = true;

  __TACOPIE_LOG(info, "tcp_client connected");
}