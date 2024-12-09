void packetQueue::bringToBack(Link node){
	Link previousPtr, currentPtr;
	previousPtr = NULL;
	currentPtr = sPtr;
	//Brings us to the correct position in the list for this item.
	if (DEBUG){
		cout << "The packet "<< node->getPacketID() << " is about to move to the back. " << endl;
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