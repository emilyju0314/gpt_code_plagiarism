tcp_client::tcp_client(tcp_socket&& socket)
	: m_io_service(get_default_io_service())
	, m_socket(std::move(socket))
	, m_disconnection_handler(nullptr) {
	m_is_connected = true;
	__MC_LOG(debug, "create tcp_client");
	m_io_service->track(m_socket);
}