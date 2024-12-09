void printGame()
{
    clearScreen();
    cout << "Deck:    ";
    if (waste != -1)
        cout << waste;
    cout << endl << endl
         << "Reserve: ";
    if (!reserve.isEmpty())
        cout << reserve.top();
    cout << endl << endl;
    for (int i=0; i<NUM_SUITS; i++) 
    {
        cout << "F" << i << "      ";
        if (foundation[i].top() > 0)
            cout << setw(2) << foundation[i].top() << "   ";
        else
            cout << "     ";
        cout <<"T" << i << ' ';
        tableau[i].print();
        cout << endl << endl;
    }

    //Display the current score.
    cout << "Score: " << score << "\n\n";

    if (playerHasWon)
        cout << "Congratulations!  You have won the game!\n\n";
}