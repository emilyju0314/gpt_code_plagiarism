Link packetQueue::getNextEvent(Link *aPtr){
	Link tempPtr;
	tempPtr = *aPtr;
	aPtr = (&(*aPtr)->next);
	tempPtr->setNext(NULL);
	return tempPtr;
}