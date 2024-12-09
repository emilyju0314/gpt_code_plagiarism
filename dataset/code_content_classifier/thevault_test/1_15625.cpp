void newShuffledPack(int *newDeck)
{
    int i, j;
    for (i=0; i<NUM_CARDS; i++)
        newDeck[i] = 1+i % NUM_RANKS; // add the cards in order
    for (i=0; i<NUM_CARDS-1; i++)     // then shuffle them
    {
        j = i+rand() % (NUM_CARDS-i); // random other card
        swap(newDeck[i], newDeck[j]); // swap them
    }
}