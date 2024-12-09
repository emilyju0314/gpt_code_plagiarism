void Graph::makeMove(Mule **thisMule, int dY, int dX){
	//First, let us check to see if we can clear the space we were at before.
	int curLocY = (*thisMule)->getLocY();
	int curLocX = (*thisMule)->getLocX();
	if((*thisMule)->getID() == manetmap[curLocY][curLocX]){
		manetmap[curLocY][curLocX] = -1;
	}
	//Now, check: is it an empty space?
	if (manetmap[(curLocY + dY)][(curLocX + dX)] == -1){
		manetmap[(curLocY + dY)][(curLocX + dX)] = (*thisMule)->getID();
		(*thisMule)->setLoc((curLocY + dY),(curLocX + dX));
        if (DEBUG){
			printf("Mule %d moved to %dY, %dX.\n", (*thisMule)->getID(), (curLocY + dY), (curLocX + dX));
		}
		return;
	}
	//Since the spot isn't empty, it has to be another mule. We'll jump onto it and move again. 
	else{
		(*thisMule)->setLoc((curLocY + dY), (curLocX + dX));
		moveMule(thisMule);
	}
}