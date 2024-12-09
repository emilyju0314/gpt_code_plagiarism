void printMenu()
{
    cout << "[q] quit [N] new game";
    if (!playerHasWon)
        cout << " [m] move [d] deal a card [r] repeat previous action";
    cout << "\nEnter your choice: ";
}