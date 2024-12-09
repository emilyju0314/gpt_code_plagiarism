void Game::calcTick() {
    
    // determine which grid is current based on time step
    Grid *current;
    Grid *future;
    if (tick % 2 == 0) {    // time step is even
        current = &evenGrid;
        future = &oddGrid;
    } else {
        current = &oddGrid;
        future  = &evenGrid;
    }
    
    // calculate future state
    int myNeighbors, myState;
    int jmax = current->getSizeY()+2*current->getHide();
    int imax = current->getSizeX()+2*current->getHide();
    for (int j = 1; j <= jmax; j++) {
        for (int i = 1; i <= imax; i++) {
            myNeighbors = current->sumNeighbors(i, j);
            myState = current->getState(i, j);
            future->setState(i, j, 0);
            if (myNeighbors == 3 || (myNeighbors == 2 && myState == 1) ) {
                future->setState(i, j, 1);
            }
        }
    }
    
    // display the result
    tick++;
    system("clear");
    std::cout << "Tick = " << tick << std::endl;
    future->displayGrid();
    usleep(100000);  // pause for 0.1 second
}