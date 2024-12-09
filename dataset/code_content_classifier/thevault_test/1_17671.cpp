void Graph::addToGrid(Receiver* thisReceiver){
	srand(time(NULL));
	int rand1;
	bool noSpot = true;
	while (noSpot){
		rand1 = rand() % dimension;
		if (manetmap[rand1][(dimension + 1)] == -1){
			noSpot = false;
			manetmap[rand1][(dimension + 1)] = thisReceiver->getID();
			thisReceiver->setLoc(rand1, (dimension + 1));
			(*items)[(thisReceiver->getID() - 1)] = (FCFS*)thisReceiver;
		} 
	}
}