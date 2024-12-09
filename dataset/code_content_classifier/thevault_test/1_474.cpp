void Game::setSeed(){
    
    // set time step to zero and fill grid with zeros
    tick = 0;
    evenGrid.clearGrid();
    
    // apply the starting pattern to the grid
    for (int i = 0; i < mySeed.getLength(); i++) {
        evenGrid.setState(xLoc + mySeed.getX(i),
                          yLoc + mySeed.getY(i), 1);
    }
    
    // display the result
    system("clear");
    std::cout << "Tick = " << tick << std::endl;
    evenGrid.displayGrid();
    usleep(1000000); // pause for 1 second
}