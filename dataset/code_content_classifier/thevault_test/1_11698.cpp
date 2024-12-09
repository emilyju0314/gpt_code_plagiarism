HttpMessage ClientHandler::closePackage(HttpMessage msg) {
	HttpMessage message;
	if (!FileSystem::Directory::exists("../TestFileServer/" + msg.findValue("dir"))) {
		message.addAttribute(HttpMessage::attribute("type", "error"));
		message.addAttribute(HttpMessage::attribute("fromAddr", msg.findValue("toAddr")));
		message.addAttribute(HttpMessage::attribute("toAddr", msg.findValue("fromAddr")));
		std::string str = "\n  no package with the name " + msg.findValue("dir");
		message.addBody(str);
		return message;
	}
	std::string name = "../TestFileServer/" + msg.findValue("dir") + "/" + msg.findValue("dir") + "." + getCurrentDate() + ".xml";
	XmlDocument doc(name, XmlDocument::file);
	sPtr close = makeTaggedElement("close");
	close->addChild(makeTextElement("true"));
	doc.xmlRoot()->addChild(close);
	FileSystem::File::remove(name);
	FileSystem::File xml(name);
	xml.open(FileSystem::File::out, FileSystem::File::text);
	if (xml.isGood()) xml.putLine(doc.toString());
	xml.close();
	return message;
}