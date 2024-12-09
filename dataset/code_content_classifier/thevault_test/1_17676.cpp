void Graph::runSimulation(){
	int simTime = 0;
	bool simulationStillInProgress = true;
	printGrid(simTime);
	while (simulationStillInProgress){
		cout << endl << "Simulation Time: " << simTime << " sims" << endl; 
		simulationStillInProgress = runARound(simTime);
		simTime++;
	}
	printGrid(simTime);
	//Build and print out all the vectors and calculations to be done.
	for(unsigned int x = (senderCount + muleCount); x < items->size(); x++){
		((Receiver*)((*items)[x]))->buildVectors(senderCount);
		((Receiver*)((*items)[x]))->printCalculations();
	}
}