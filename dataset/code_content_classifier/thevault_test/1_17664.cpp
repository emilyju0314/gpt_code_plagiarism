bool nodeOperations::addEvent(Link thisEvent){
	Link previousPtr, currentPtr;
	//check to make sure we have room in memory
	if(thisEvent){
		//add the pieces of information to the pointer
		currentPtr = sPtr;
		//Brings us to the correct position in the list for this item.
		while (currentPtr!=NULL && thisEvent->getArrivalTime() > currentPtr->getArrivalTime()){
			previousPtr = currentPtr;
			currentPtr = currentPtr->getNext();
		}
		//Are we at the beginning?
		if(previousPtr == NULL){
			thisEvent->setNext(sPtr);
			sPtr = thisEvent;
			return true;
		}
		//Now we're adding it to somewhere in the list
		else{
			previousPtr->setNext(thisEvent);
			thisEvent->setNext(currentPtr);
			return true;
		}
	}
	//Not enough memory otherwise
	else{
		printf("Uhmmm, we don't have enough memory to insert Process %d.", thisEvent->getPacketID());
		return false;
	}
}