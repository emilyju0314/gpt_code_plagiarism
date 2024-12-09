void
tcp_client::connect(const std::string& host, std::uint32_t port) {
	if (is_connected()) { __MC_THROW(warn, "tcp_client is already connected"); }

	try {
		m_socket.connect(host, port);
		m_io_service->track(m_socket);
	}

	catch (const mc_error& e) {
		m_socket.close();
		throw e;
	}

	m_is_connected = true;
	__MC_LOG(info, "tcp_client connected");
}