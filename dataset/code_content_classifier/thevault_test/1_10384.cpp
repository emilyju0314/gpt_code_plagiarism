void dealDeck(vector<vector<vector<int>>> &playerHands, vector<vector<int>> &deck)
{
	srand(time(NULL));
	int handSize = 52/(playerHands.size());
	int index, spadesSize, diamondSize, clubSize, heartSize;
	double random1, random2, random3, random4, randSum;

	//Adds 4 suit arrays for each player
	for(int i = 0; i < playerHands.size(); i++)
	{
		for(int j = 0; j < 4; j++)
		{
			vector<int> suit;
			playerHands[i].push_back(suit);
		}
	}

	int cycler = 0, card = 0;
	int dealableDeck = 52-(52%playerHands.size());
	bool flagUp = false;

	//keep dealing cards while there are cards left to deal
	while(dealableDeck > 0)
	{
		int suit = rand()%4;

		if(deck[suit][card] != -1)
			playerHands[cycler][suit].push_back(deck[suit][card]);
		else
			flagUp = true;

		deck[suit][card] = -1;
		cycler++;
		card++;
		dealableDeck--;
		if(flagUp)
		{
			cycler--;
			card--;
			dealableDeck++;
			flagUp = false;
		}
		if(cycler >= playerHands.size())
			cycler = 0;
		
		if(card >= 13)
			card = 0;
		
	}
	//Sorts each player's cards in ascending order
	for(int i = 0; i < playerHands.size(); i++)
	{
		for(int j = 0; j < playerHands[i].size(); j++)
		{
			sort(playerHands[i][j].begin(), playerHands[i][j].end());
		}
	}


		/*
		random1 = rand()%30;
		random2 = rand()%30;
		random3 = rand()%30;
		random4 = rand()%30;
		randSum = random1+random2+random3+random4;

		spadesSize = (random1/randSum)*handSize;
		diamondSize = (random2/randSum)*handSize;
		clubSize = (random3/randSum)*handSize;
		heartSize = (random4/randSum)*handSize;

		cout << endl<< handSize << "   " << randSum << "   " << random1 << "   " << random2 << "   " << random3 << "   " << random4;
		cout << "\n" << i << " Player - Spades size: " << spadesSize;
		cout << "\n" << i << " Player - diamonds size: " << diamondSize;
		cout << "\n" << i << " Player - club size: " << clubSize;
		cout << "\n" << i << " Player - heart size: " << heartSize;
		
		playerHands[i][0].resize(spadesSize);
		playerHands[i][1].resize(diamondSize);
		playerHands[i][2].resize(clubSize);
		playerHands[i][3].resize(heartSize);
		
		for(int j = 0; j < 4; j++)
		{
			

			for(int q = 0; q < playerHands[i][j].size(); q++)
			{
				index = rand()%(deck[j].size());
				while(deck[j][index] == -1)
				{
					index = rand()%(deck[j].size());
				}

				playerHands[i][j][q] = deck[j][index];
				deck[j][index] = -1;
			}
		}*/
}