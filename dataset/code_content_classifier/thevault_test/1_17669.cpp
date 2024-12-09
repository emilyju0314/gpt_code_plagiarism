void Graph::addToGrid(Sender* thisSender){
	srand(time(NULL));
	int rand1;
	bool noSpot = true;
	while (noSpot){
		rand1 = rand() % dimension;
		if (manetmap[rand1][0] == -1){
			noSpot = false;
			thisSender->setLoc(rand1, 0);
			manetmap[rand1][0] = thisSender->getID();
			(*items)[(thisSender->getID() - 1)] = (FCFS*)thisSender;
		} 
	}
}