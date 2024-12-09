void BinarySearchTree::printTree(BinarySearchNode *start){
	if(start != NULL){
		printTree(start->getLeft());
		start->printNode();
		printTree(start->getRight());
	}
}