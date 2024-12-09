void FCFS::propogationSimulation(FCFS **next, int simTime){
	//traverses sProcPtr and decrements the propogation time by one for each. Removes the first from the propogation quene 
	if(propogationQuene.decrementTime() == true){
		Link thisNode = propogationQuene.getNextEvent();
		if ((*next)->getPropogationTime() == -1){
			(*((Receiver**)next))->addEventReceiverSpecial(thisNode);
			return;
		}
		(*next)->addEvent(thisNode);
	}
}