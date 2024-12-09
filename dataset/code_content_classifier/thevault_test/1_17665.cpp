void nodeOperations::bringToBack(Link node){
	Link previousPtr, currentPtr;
	previousPtr = NULL;
	currentPtr = sPtr;
	//Brings us to the correct position in the list for this item.
	if (DEBUG){
		printf("The node %d is about to move into place\n", node->getPacketID());
	}
	while (currentPtr != NULL){
		previousPtr = currentPtr;
		currentPtr = currentPtr->getNext();
	}
	//Are we at the beginning?
	if(previousPtr == NULL){
		node->setNext(NULL);
		sPtr = node;
	}
	//Now we're adding it to the end in the list
	else{
		previousPtr->setNext(node);
		node->setNext(NULL);
	}
}