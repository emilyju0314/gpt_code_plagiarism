HttpMessage ClientHandler::getFileNameList(HttpMessage msg) {
	std::vector<std::string> fileList = FileSystem::Directory::getFiles("../TestFileServer/" + msg.findValue("dir"));
	std::string body = "";
	for (size_t i = 0; i < fileList.size(); ++i)
		if (fileList[i] != "." && fileList[i] != "..")
			body += "\n  " + fileList[i];
	body += "\n";
	HttpMessage message;
	message.addAttribute(HttpMessage::attribute("fromAddr", msg.findValue("toAddr")));
	message.addAttribute(HttpMessage::attribute("toAddr", msg.findValue("fromAddr")));
	message.addAttribute(HttpMessage::attribute("type", "returnList"));
	message.addBody(body);
	return message;
}