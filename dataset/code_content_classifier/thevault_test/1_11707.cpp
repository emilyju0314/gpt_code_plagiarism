HttpMessage ClientHandler::getFiles(HttpMessage msg, std::string type) {
	HttpMessage message;
	if (!FileSystem::Directory::exists("../TestFileServer/" + msg.bodyString()))
		return errorMessage(msg, "\n  no package " + msg.bodyString());
	std::string path = "../TestFileServer/" + msg.bodyString() + "/";
	std::vector<std::string> files = FileSystem::Directory::getFiles(path, "*.ver*");
	if (files.size() == 0) return errorMessage(msg, "\n  so files in package " + msg.bodyString());
	std::vector<std::string> sendFiles;
	for (int i = files.size() - 1; i >= 0; --i) { // figure out the latest version of the files
		std::string ext = files[i].substr(files[i].find_last_of(".") + 1);
		if (ext == "xml") continue;
		std::string name = files[i].substr(0, files[i].find_last_of("."));
		if (find(sendFiles, name) == sendFiles.size())
			sendFiles.push_back(files[i]); // add only unique file names to be sent
	}
	std::vector<std::shared_ptr<AbstractXmlElement>> deps;
	if (type == "FileWithDeps") { // figure out dependencies of files to be sent
		for (int i = 0; i < sendFiles.size(); ++i) {
			std::string file = sendFiles[i];
			if (!FileSystem::File::exists("../TestFileServer/" + msg.bodyString() + "/" + file)) continue;
			std::string xmlname = "../TestFileServer/" + msg.bodyString() + "/" + file + ".xml";
			XmlDocument doc(xmlname, XmlDocument::file);
			deps = doc.element("deps").descendents().select();
			for (auto dep : deps)
				if (dep->tag() == "") { // prevent circular dependencies to be stuck in a loop
					std::string depName = dep->value().substr(0, dep->value().find("\n"));
					if (find(sendFiles, depName.substr(0, depName.find_last_of("."))) == sendFiles.size()) sendFiles.push_back(depName);
				}
		}
	}
	std::string body;
	for (size_t i = 0; i < sendFiles.size() - 1; ++i) body += sendFiles[i] + ",";
	body += sendFiles[sendFiles.size() - 1];
	message.addAttribute(HttpMessage::attribute("fromAddr", msg.findValue("toAddr")));
	message.addAttribute(HttpMessage::attribute("toAddr", msg.findValue("fromAddr")));
	message.addAttribute(HttpMessage::attribute("type", "returnFiles"));
	message.addBody(body);
	return message;
}