HttpMessage ClientHandler::readBody(HttpMessage msg, Socket& socket) {
	size_t numBytes = 0;
	size_t pos = msg.findAttribute("content-length");
	HttpMessage message = msg;
	if (pos < msg.attributes().size()) {
		numBytes = Converter<size_t>::toValue(msg.attributes()[pos].second);
		Socket::byte* buffer = new Socket::byte[numBytes + 1];
		socket.recv(numBytes, buffer);
		buffer[numBytes] = '\0';
		std::string msgBody(buffer);
		message.addBody(msgBody);
		delete[] buffer;
	}
		return message;
}