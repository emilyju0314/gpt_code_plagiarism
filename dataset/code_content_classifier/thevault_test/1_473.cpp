int Game::getUserInput() {
    int choice = 1;
    
    // display a menu and get user choice of starting pattern
    std::cout << "Choose a seed pattern:" << std::endl;
    std::cout << "1) Blinker" << std::endl;
    std::cout << "2) Glider" << std::endl;
    std::cout << "3) Gosper Glider Gun" << std::endl;
    std::cout << "Enter a value from 1 to 3: ";
    std::cin >> choice;
    while ((choice < 1) || (choice > 3))
    {
        std::cout << "ERROR: Enter a value from 1 to 3: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    switch (choice) {
        case 1:
            patternName = "blinker";
            break;
        case 2:
            patternName = "glider";
            break;
        case 3:
            patternName = "gosperglidergun";
            break;
            
        default:
            break;
    }
    
    // read pattern file
    mySeed.readFile(patternName);
    std::cout << std::endl;
    std::cout << "The dimensions of the seed pattern are ";
    std::cout << mySeed.getSizeX() << " x " << mySeed.getSizeY() << std::endl;

    // calculate safe range for starting location
    int x1 = mySeed.getSizeX()/2 + 1;
    int x2 = evenGrid.getSizeX() - mySeed.getSizeX()/2;
    int y1 = mySeed.getSizeY()/2 + 1;
    int y2 = evenGrid.getSizeY() - mySeed.getSizeY()/2;
    
    // display a menu and get user choice of starting location
    std::cout << std::endl;
    std::cout << "Choose location to center the seed pattern: ";
    std::cout << std::endl;
    std::cout << "Enter a horizontal coordinate from ";
    std::cout << x1 << " to ";
    std::cout << x2;
    std::cout << " (left to right): ";
    std::cin >> xLoc;
    while ((xLoc < x1) || (xLoc > x2))
    {
        std::cout << "ERROR: Enter a value from " ;
        std::cout << x1 << " to ";
        std::cout << x2 << ": ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> xLoc;
    }
    std::cout << std::endl;
    std::cout << "Enter a vertical coordinate from ";
    std::cout << y1 << " to ";
    std::cout << y2;
    std::cout << " (top to bottom): ";
    std::cin >> yLoc;
    while ((yLoc < y1) || (yLoc > y2))
    {
        std::cout << "ERROR: Enter a value from " ;
        std::cout << y1 << " to ";
        std::cout << y2 << ": ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> yLoc;
    }
    
    // adjust location to account for hidden cells
    xLoc = xLoc + evenGrid.getHide();
    yLoc = yLoc + evenGrid.getHide();
    
    // get user choice of number of time steps
    int nsteps;
    std::cout << std::endl;
    std::cout << "Enter number of time steps (ticks): ";
    std::cin >> nsteps;
    while (nsteps < 1)
    {
        std::cout << "ERROR: Please enter a positive number" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> nsteps;
    }
    return nsteps;
}