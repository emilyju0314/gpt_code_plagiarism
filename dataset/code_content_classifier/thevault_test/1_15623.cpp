void canfield()
{
    char answer;
    srand(time(NULL));
    newGame();
    printGame();
    while (!quit) 
    {
        printMenu();
        cin >> answer;
        performAction(answer);
    }
}