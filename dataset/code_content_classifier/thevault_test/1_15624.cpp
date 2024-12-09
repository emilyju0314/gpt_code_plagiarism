void newGame()
{
    int i, card;
    int cardsLeft = NUM_CARDS;
    int newDeck[NUM_CARDS];

    // Empty all the data structures
    emptyAll();

    //Reset the score.
    score = 0;

    //Reset the flag that declares whether the player has won the game or not.
    playerHasWon = false;

    // Create a new deck and shuffle it
    newShuffledPack(newDeck);

    // Now place the cards in the data structures
    for (i=0; i<NUM_RANKS; i++)      // fill in the reserve with 13 cards
    {
        card = newDeck[--cardsLeft]; // use a card and decrease the total count
        reserve.push(card);
    }
    for (i=0; i<NUM_SUITS; i++)      // draw a card for each tableau
    {
        card = newDeck[--cardsLeft]; // use a card and decrease the
                                     // total count
        tableau[i].push(card);
    }
    for (i=0; i<NUM_SUITS; i++)      // Initialize the foundations with 0
        foundation[i].push(0);
    waste = newDeck[--cardsLeft];    // the card to play
    while (cardsLeft > 0)            // the remaining cards go into the deck
    {
        card = newDeck[--cardsLeft];
        deck.enqueue(card);
    }
}