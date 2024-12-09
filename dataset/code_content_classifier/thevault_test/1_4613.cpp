Player * RankManager::createNewPlayer(string name, string userName, string passWord, int score) {

	Player *player = new Player(userName, name, passWord, score);
	playersInMem->push_back(player); // add the player to the vector of players
	sortAndRankPlayers(playersInMem);
	setRankingsToFile(playersInMem, ranksFile); // update the rankings file, game will take care of updating the score file as needed
	return player;
}