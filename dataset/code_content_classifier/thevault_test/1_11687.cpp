void Client::testType1(Sender& sndr, int timeout) {
	HttpMessage message;
	Utils::title("Sending package Logger");
	putline();
	HttpMessage msg = sndr.makeMessage(1, "Logger,Logger.h,Sockets.h,Sockets.cpp", remoteUrl);
	sndr.postFile(msg);
	::Sleep(timeout);
	msg = sndr.makeMessage(1, "Logger,Logger.cpp,Sockets.h,Sockets.cpp", remoteUrl);
	sndr.postFile(msg);
	::Sleep(timeout);

	Utils::title("Sending package Sockets");
	putline();
	msg = sndr.makeMessage(1, "Sockets,Sockets.h,Logger.h.ver1", remoteUrl);
	sndr.postFile(msg);
	::Sleep(timeout);
	msg = sndr.makeMessage(1, "Sockets,Sockets.cpp,Logger.cpp.ver2", remoteUrl);
	sndr.postFile(msg);
	std::cout << "-------< please verify the XML files created for these two packages >-------\n";
	::Sleep(timeout);

}