sPtr ClientHandler::makeFileElement(sPtr pRoot, std::string package, std::string filename, std::vector<std::string> deps) {
	sPtr file = makeTaggedElement("file");
	file->addChild(makeTextElement(filename));
	sPtr depNames = makeTaggedElement("deps");
	for (auto depName : deps) {
		sPtr dep = makeTaggedElement("dep");
		dep->addChild(makeTextElement(depName));
		depNames->addChild(dep);
	}
	file->addChild(depNames);
	pRoot->addChild(file);
	return pRoot;
}