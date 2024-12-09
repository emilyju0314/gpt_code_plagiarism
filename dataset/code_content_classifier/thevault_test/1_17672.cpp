void Graph::moveMule(Mule **thisMule){
	int dY = 0;
	int dX = 0;
	switch((*thisMule)->getDirection()){
		case NORTH:
			if((*thisMule)->getLocY() == 0){
				(*thisMule)->invertDirection();
			}
			else{
				dY = -1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case SOUTH:
			if((*thisMule)->getLocY() == (dimension - 1)){
				(*thisMule)->invertDirection();
			}
			else{
				dY = 1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case EAST:
			if((*thisMule)->getLocX() == dimension) {
				(*thisMule)->invertDirection();
			}
			else{
				dX = 1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case WEST:
			if((*thisMule)->getLocX() == 1){
				(*thisMule)->invertDirection();
			}
			else{
				dX = -1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case EMPTY:
			break;
		default:
			printf("There was some sort of error with moving %d.\n", (*thisMule)->getID());
			break;
	}
}