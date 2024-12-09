void Client::testType6(Sender& sndr, int timeout) {
	HttpMessage message;
	Utils::title("Requesting list of files in the Socket package");
	putline();
	HttpMessage msg = sndr.makeMessage(6, "Sockets.2016.5.6", remoteUrl);
	sndr.postMessage(msg);
	::Sleep(timeout);
}