void Client::testType5(Sender& sndr, int timeout) {
	HttpMessage message;
	Utils::title("Requesting list of packages from server");
	putline();
	HttpMessage msg = sndr.makeMessage(5, "", remoteUrl);
	sndr.postMessage(msg);
	::Sleep(timeout);
}