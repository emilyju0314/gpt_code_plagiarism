void updateScore()
{
    //Only add to the score if a card was moved to a foundation.
    if (to == 'f' || to == 'F')
        //Preincrement score then check to see if it is equal to the number of cards the game was
        //played with.  If it is, then the player has won and the flag is set indicating as much.
        if (++score == NUM_CARDS)
            playerHasWon = true;
}