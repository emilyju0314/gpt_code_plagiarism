bool nodeOperations::decrementTime(){
	Link tempPtr = sPtr;
	while (tempPtr != NULL){
		 tempPtr->setPropogationTime((tempPtr->getPropogationTime()-1));
		 if (DEBUG){
		 	printf("%d has a propogation time of %d. The quene size is %d.\n", tempPtr->getPacketID(), tempPtr->getPropogationTime(), getLength());
		 }
		 tempPtr = tempPtr->getNext();
	}
	if(sPtr->getPropogationTime() == 0){
		return true;
	}
	return false;
}