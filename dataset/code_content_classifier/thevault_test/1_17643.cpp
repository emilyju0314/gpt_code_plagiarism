void BinarySearchNode::addLine(int line){
	count++;
	if(listOfLines.size() == 0 || listOfLines.back() != line){
		listOfLines.push_back(line);
	}
}