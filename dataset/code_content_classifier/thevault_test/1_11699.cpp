void ClientHandler::saveFileClient(HttpMessage msg, Socket& socket) {
	std::string filename = msg.findValue("file").substr(msg.findValue("file").find_last_of("/") + 1);
	std::string path = "../TestFileClient/";
	FileSystem::Directory::create(path);
	size_t contentSize;
	std::string sizeString = msg.findValue("content-length");
	if (sizeString != "")
		contentSize = Converter<size_t>::toValue(sizeString);
	else
		return;
	readFile(filename, contentSize, socket, path);
}