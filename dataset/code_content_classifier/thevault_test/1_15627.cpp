void performAction(char answer)
{
    switch (answer) 
    {
        case 'q':
        case 'Q':
            quit = true;
            break;
            //case 'n': this causes problems because it's next to m
        case 'N':
            newGame();
            break;
        case 'm':
        case 'M':
            if (!playerHasWon)
                move();
            break;
        case 'd':
        case 'D':
            if (!playerHasWon)
                deal();
            break;
        case 'r':
        case 'R':
            //Repeat the last move the user made, if possible.
            if (!playerHasWon)
                move(true);
            break;
    }
    if (!quit)
        printGame();
}