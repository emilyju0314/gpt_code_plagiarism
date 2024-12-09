void fillDeck(vector<vector<int>> &deck)
{
	srand(time(NULL));

	//fills the deck vector with 4 suits
	for(int q = 0; q < deck.size(); q++)
	{
		vector<int> suit;
		deck[q] = suit;
	}

	//resizes each suit to be 13 cards
	for(int i = 0; i < deck.size(); i++)
	{
		deck[i].resize(13);
		//fills each suit with a card counting up
		for(int j = 0; j < deck[i].size(); j++)
		{
			deck[i][j] = j + 1;
		}

		random_shuffle(deck[i].begin(), deck[i].end());
	}
}