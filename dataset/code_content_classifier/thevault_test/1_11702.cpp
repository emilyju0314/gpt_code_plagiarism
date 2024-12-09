XmlDocument ClientHandler::builDocument(std::string filename, std::vector<std::string> deps) {
	using sPtr = std::shared_ptr<AbstractXmlElement>;
	sPtr pRoot = makeTaggedElement("metadata");
	XmlDocument doc(XmlProcessing::makeDocElement(pRoot));

	sPtr name = makeTaggedElement("name");
	name->addChild(makeTextElement(filename));
	pRoot->addChild(name);
	sPtr depNames = makeTaggedElement("deps");
	for (auto depName : deps) {
		sPtr dep = makeTaggedElement("dep");
		dep->addChild(makeTextElement(depName));
		depNames->addChild(dep);
	}
	pRoot->addChild(depNames);
	return doc;
}