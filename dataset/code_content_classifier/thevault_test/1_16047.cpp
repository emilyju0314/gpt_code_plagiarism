void
io_service::wait_for_removal(const tcp_socket& socket) {
  std::unique_lock<std::mutex> lock(m_tracked_sockets_mtx);

  __TACOPIE_LOG(debug, "waiting for socket removal");

  m_wait_for_removal_condvar.wait(lock, [&]() {
    __TACOPIE_LOG(debug, "socket has been removed");

    return m_tracked_sockets.find(socket.get_fd()) == m_tracked_sockets.end();
  });
}