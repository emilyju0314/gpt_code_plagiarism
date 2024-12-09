vector<Link> packetQueue::decrementTime(){
	vector<Link> whatsBeenMade;
	Link previousPtr = NULL;
	Link currentPtr, tempPtr;
	currentPtr = sPtr;
	if (DEBUG){
	}
	if (sPtr == NULL){
		return whatsBeenMade;
	}
	while (currentPtr){
		if (currentPtr->getPropogationTime() <= 0){
			if (previousPtr == NULL){
				sPtr = currentPtr->next;
			}
			else{
				previousPtr->next = currentPtr->next;
			}
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			tempPtr->next = NULL;
			whatsBeenMade.push_back(tempPtr);
		}
		else{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
	}
	if (sPtr != NULL){
		sPtr = sPtr->decrementItems();
	}
	return whatsBeenMade;
}