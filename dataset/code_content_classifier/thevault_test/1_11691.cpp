void Client::testType3(Sender& sndr, int timeout) {
	HttpMessage message;
	Utils::title("Requesting package Logger with all of its dependencies");
	putline();
	HttpMessage msg = sndr.makeMessage(3, "Logger.2016.5.6", remoteUrl);
	sndr.postMessage(msg);
	::Sleep(timeout);
}