bool Graph::runARound(int simTime){
	bool simulationStillInProgress = false;
	for(unsigned int y = 0; y < items->size(); y++){
		FCFS *thisFCFS = ((*items)[y]);
		bool tempBool = false;
		//Run any sender activity
		if(y < (unsigned int)(senderCount) && thisFCFS->getArrivalTime() <= simTime){
			if (y == 0) {
				cout << endl << "The Sender activities follow here:" << endl;
			}
			tempBool = ((Sender*)thisFCFS)->runner(&items, simTime);
			(*items)[y] = thisFCFS;
		}
		//Run any mule activity
		else if (y < (unsigned int)(senderCount + muleCount) && thisFCFS->getArrivalTime() <= simTime){
			if (y == (unsigned int)senderCount){
				cout << endl << "The Mule activities follow here:" << endl;
			}
			tempBool = ((Mule*)thisFCFS)->runner(&items, simTime);
			(*items)[y] = thisFCFS;
		}
		if (tempBool == true){
			simulationStillInProgress = true;
		}
	}
	//Make moves if the time is right
	if ((simTime % 10 == 0) && (simTime != 0)){
		moveManyMules();
	}
	//Print board if the time is right
	if((simTime % 100 == 0) && (simTime != 0)){
		printGrid(simTime);
	}
	return simulationStillInProgress;
}