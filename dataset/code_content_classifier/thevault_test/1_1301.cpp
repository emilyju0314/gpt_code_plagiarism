void callback(const boost::system::error_code& ec,
	std::size_t bytes_transferred,
	std::shared_ptr<Session> s)
{
	if (ec != 0) {
		std::cout << "Error occured! Error code = "
			<< ec.value()
			<< ". Message: " << ec.message();

		return;
	}

	s->total_bytes_written += bytes_transferred;

	if (s->total_bytes_written == s->buf.length()) {
		return;
	}

	s->sock->async_write_some(
		asio::buffer(
		s->buf.c_str() +
		s->total_bytes_written,
		s->buf.length() -
		s->total_bytes_written),
		std::bind(callback, std::placeholders::_1,
		std::placeholders::_2, s));
}