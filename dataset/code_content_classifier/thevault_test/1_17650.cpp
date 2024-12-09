int packetQueue::getLength(){
	Link tempPtr = sPtr;
	int counter = 0;
	while (tempPtr != NULL){
		 counter += 1;
		 tempPtr = tempPtr->getNext();
	}
	return counter;
}