BinarySearchNode::BinarySearchNode(string aword, int line){
	word = aword;
	count = 0;
	LeftNode = NULL;
	RightNode = NULL;
	addLine(line);
}