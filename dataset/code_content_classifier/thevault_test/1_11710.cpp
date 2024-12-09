void ClientHandler::sendMessage(HttpMessage msg) {
	HttpMessage message;
	Sender sndr(msg.findValue("fromAddr"));
	sndr.start();
	message = sndr.makeMessage(0, msg.bodyString(), msg.findValue("toAddr"));
	sndr.postMessage(message);
	sndr.postMessage(sndr.makeMessage(0, "closeServer", msg.findValue("toAddr")));
	sndr.postMessage(sndr.makeMessage(0, "quit", msg.findValue("toAddr")));
	sndr.wait();
}