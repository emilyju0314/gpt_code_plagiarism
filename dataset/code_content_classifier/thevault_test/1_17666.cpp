Link nodeOperations::getNextEvent(){
	Link tempPtr;
	tempPtr = sPtr;
	sPtr = (sPtr)->getNext();
	tempPtr->setNext(NULL);
	return tempPtr;
}