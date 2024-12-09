void Client::testType7(Sender& sndr, int timeout) {
	HttpMessage message;
	Utils::title("Closing Logger package");
	putline();
	HttpMessage msg = sndr.makeMessage(7, "Logger", remoteUrl);
	sndr.postMessage(msg);
	::Sleep(timeout);
}