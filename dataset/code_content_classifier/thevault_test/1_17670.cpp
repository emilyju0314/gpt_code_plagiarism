void Graph::addToGrid(Mule* thisMule){
	srand(time(NULL));
	int rand1, rand2;
	bool noSpot = true;
	while (noSpot){
		rand1 = rand() % dimension;
		rand2 = rand() % dimension;
		if (manetmap[rand1][(rand2 + 1)] == -1){
			noSpot = false;
			manetmap[rand1][rand2 + 1] = thisMule->getID();
			thisMule->setLoc(rand1, (rand2 + 1));
			(*items)[(thisMule->getID() - 1)] = (FCFS*)thisMule;  
		} 
	}
}