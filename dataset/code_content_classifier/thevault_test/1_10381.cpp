void startGame(int &numPlayers)
{
	string directions = "The object of the game:\nPlayers don't want to end up with tricks containing hearts or the queen of spades, but they do want to end up with the jack of diamonds.\n\nHow many can play:\nFour to seven players (four players is the best!)\n\nThe cards:\nYou need a standard deck of 52 cards. Each player is dealt the same number of cards. So, if you have 4 players, each receives 13 cards (13 x 4 = 52). In each suit, the cards are ranked from the Ace, with the highest value, on down: K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3, and 2.\n\nHow to deal:\nAfter the cards have been dealt, each player chooses three cards to pass to an opponent. Players pick their cards after they've looked at them, and before they've received cards from their opponents. At the fourth deal, players keep their own cards.\n\nHow to play:\nThe player holding the 2 of clubs card starts first. Each player after the lead must follow suit if he can. If he can't, he may play any card he wants.\nA player wins a trick when he plays the highest card of the suit that is led. The winner of the trick leads the next.\n\nHow to keep score:\nAfter all the cards have been played, players count up their tricks. Each player receives a penalty point for each heart card they have. The player who ends up with the queen of spades gets 13 points. Here's a bonus: the player who ends up with the jack of diamonds gets to subtract 10 points from his score.\nThe player with least number of points when any player reaches 50 points wins.";
	system("cls");
	cout << "This is the game of hearts.\n\n" << directions;
	cout << endl << endl;
	cout << "How many players in this game? (4-7, 4 reccommended)\n";
	cin >> numPlayers;

	//checks to make sure there are a valid number of players
	while(numPlayers < 4 || numPlayers > 7)
	{
		cout << endl << "Invalid number. How many players in this game? (4-7)\n";
		cin >> numPlayers;
	}
}