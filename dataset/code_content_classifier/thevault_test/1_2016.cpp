bool remote::RemoteDeviceMessage::send(boost::asio::ip::tcp::socket &socket) {
	report("OcelotServerConnection::send() - " << header);
	try {
		size_t len = boost::asio::write( socket, boost::asio::buffer((char *)&header, sizeof(header)));

		assert(len == sizeof(header));
		
		len = boost::asio::write( socket, boost::asio::buffer(message));

	}
	catch (std::exception &exp) {
		std::cerr << "RemoteDeviceMessage::send() - " << exp.what() << std::endl;
	}
	return true;
}