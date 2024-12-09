int BinarySearchTree::numOfWords(BinarySearchNode *start){
	if(start != NULL){
		int num = 1;
		num+=numOfWords(start->getLeft());
		num+=numOfWords(start->getRight());
		return num;
	}
	return 0;
}