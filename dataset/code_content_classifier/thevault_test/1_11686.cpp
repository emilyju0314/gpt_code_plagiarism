void Client::testType0(Sender& sndr, int timeout) {
	Utils::title("Sending 5 test messages");
	putline();
	HttpMessage message;
	for (int i = 1; i <= 5; i++) {
		std::string body = "Test Message #" + i;
		message = sndr.makeMessage(0, body, remoteUrl);
		sndr.postMessage(message);
		::Sleep(timeout);
	}
}