bool BinarySearchTree::insert(string aword, int line, BinarySearchNode **start){
	//If the start pointer is empty, set the new node equal to the start
	if (*start == NULL){
		BinarySearchNode *thisNode = new BinarySearchNode(aword, line);
		(*start) = thisNode;
		return true;
	}
	//Compares the word of the start to the word at the end
	int comparison = (*start)->getWord().compare(aword);
	//If the same, only add a line
	if (comparison == 0){
		(*start)->addLine(line);
		return false;
	}
	//Moves to the left node if the comparison is greater
	if (comparison > 0){
		return insert(aword, line, &(*start)->LeftNode);
	}
	//Moves to the Right node if the comparison is lesser
	if (comparison < 0){
		return insert(aword, line, &(*start)->RightNode);
	}
	//checks to ensure if it actually worked
	else{
		cout << "huh??" << endl;
		return false;
	}
	return false;
}