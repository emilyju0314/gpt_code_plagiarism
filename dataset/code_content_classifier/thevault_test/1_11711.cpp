void ClientHandler::operator()(Socket socket) {
	std::function<void()> threadProc = [&]() {
		while (true) {
			HttpMessage msg = readMessage(socket); // read a message from socket
			if (msg.attributes().size() == 0 || msg.bodyString() == "quit") break;
			if (msg.findValue("type") == "returnList") {
				sendMessage(msg);
				continue;
			}
			else if (msg.findValue("type") == "returnFiles") {
				Sender sndr(msg.findValue("fromAddr"));
				sndr.start();
				std::vector<std::string> files = splitString(msg.bodyString());
				for (std::string file : files) {
					std::string fileSpec = searchFile(file);
					FileSystem::FileInfo fi(fileSpec);
					FileSystem::File fileIn(fileSpec);
					fileIn.open(FileSystem::File::in, FileSystem::File::binary);
					if (!fileIn.isGood()) {
						std::cout << "\n  could not open file " << file;
						continue;
					}
					size_t fileSize = fi.size();
					std::string sizeString = Converter<size_t>::toString(fileSize);
					HttpMessage message = sndr.makeMessage(4, "", msg.findValue("toAddr"));
					message.addAttribute(HttpMessage::Attribute("file", fileSpec));
					message.addAttribute(HttpMessage::Attribute("content-length", sizeString));
					sndr.postMessage(message);
				}
				sndr.postMessage(sndr.makeMessage(0, "closeServer", msg.findValue("toAddr")));
				sndr.postMessage(sndr.makeMessage(0, "quit", msg.findValue("toAddr")));
				sndr.wait();
				continue;
			}
			else if (msg.attributes()[0].second == "error") {
				sendMessage(msg);
				continue;
			}
			msgQ_.enQ(msg);
		}
	};
	std::thread receiveThread(threadProc);
	receiveThread.join();
}