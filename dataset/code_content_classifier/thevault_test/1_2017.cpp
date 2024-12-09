bool remote::RemoteDeviceMessage::receive(boost::asio::ip::tcp::socket &socket) {
	report("OcelotServerConnection::receive()");
	
	try {
		boost::array<char, sizeof(RemoteDeviceMessage::Header)> headerBuffer;
		boost::system::error_code error;

		size_t len = boost::asio::read(socket, boost::asio::buffer(headerBuffer));
		
		std::memcpy(&header, headerBuffer.data(), len);
		
		report("  header: " << header);
		
		resize();
		len = boost::asio::read(socket, boost::asio::buffer(message));
		
	}
	catch (std::exception &exp) {
		std::cerr << "RemoteDeviceMessage::receive() - " << exp.what() << std::endl;
		return false;
	}
	
	report("Received message: " << RemoteDeviceMessage::toString(header.operation) 
		<< " [device " << header.deviceId << "]");
	
	return true;
}