void ClientHandler::updateXML(std::string package, std::string filename, std::vector<std::string> deps) {
	if (FileSystem::File::exists("../TestFileServer/" + package + "/" + package + ".xml")) {
		XmlDocument doc("../TestFileServer/" + package + "/" + package + ".xml", XmlDocument::file);
		for (auto file : doc.elements("file").select()) {
			if (file->tag() == "")
				if (file->value().substr(0, file->value().find("\n")) == filename) return;
		}
		sPtr file = makeFileElement(doc.xmlRoot(), package, filename, deps);
		FileSystem::File::remove("../TestFileServer/" + package + "/" + package + ".xml");
		FileSystem::File xml("../TestFileServer/" + package + "/" + package + ".xml");
		xml.open(FileSystem::File::out, FileSystem::File::text);
		if (xml.isGood()) xml.putLine(doc.toString());
		xml.close();
	}

	else {
		sPtr pRoot = makeTaggedElement("metadata");
		XmlDocument doc(XmlProcessing::makeDocElement(pRoot));
		sPtr name = makeTaggedElement("name");
		name->addChild(makeTextElement(package));
		pRoot->addChild(name);
		sPtr file = makeFileElement(pRoot, package, filename, deps);
		FileSystem::File xml("../TestFileServer/" + package + "/" + package + ".xml");
		xml.open(FileSystem::File::out, FileSystem::File::text);
		if (xml.isGood()) xml.putLine(doc.toString());
		xml.close();
	}
}