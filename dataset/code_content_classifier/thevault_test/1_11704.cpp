HttpMessage ClientHandler::constructMessage(HttpMessage msg, std::string body) {
	Sender sndr(msg.findValue("toAddr"));
	HttpMessage message = sndr.makeMessage(0, body, msg.findValue("fromAddr"));
	return message;
}