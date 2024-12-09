void ClientHandler::saveFileServer(HttpMessage msg, Socket& socket) {
	FileSystem::Directory::create("../TestFileServer/");
	std::string filename = msg.findValue("file") + ".ver1";
	std::string packageName = msg.findValue("dir") + "." + getCurrentDate();
	std::string path = "../TestFileServer/" + packageName + "/";
	FileSystem::Directory::create(path);
	std::string dependencies = msg.findValue("deps");
	std::vector<std::string> deps;
	if(dependencies != "") deps = findDeps(dependencies);
	std::vector<std::string> files;
	for (auto fileSpec : FileSystem::Directory::getFiles(path, msg.findValue("file") + ".ver*"))
		if (fileSpec.substr(fileSpec.find_last_of(".")) != ".xml") files.push_back(fileSpec);
	if (files.size() > 0) {
		std::string name = files[files.size() - 1];
		int ver = std::stoi(name.substr(name.find_last_of(".") + 4));
		filename = msg.findValue("file") + ".ver" + std::to_string(ver + 1);
	}

	std::string xmlpath = path + filename + ".xml";
	XmlDocument doc = builDocument(filename, deps);
	FileSystem::File file(xmlpath);
	
	file.open(FileSystem::File::out, FileSystem::File::text);
	if (file.isGood())
		file.putLine(doc.toString());
	file.close();

	size_t contentSize;
	std::string sizeString = msg.findValue("content-length");
	if (sizeString != "")
		contentSize = Converter<size_t>::toValue(sizeString);
	else
		return;
	readFile(filename, contentSize, socket, path);
	updateXML(packageName, msg.findValue("file"), deps);
}