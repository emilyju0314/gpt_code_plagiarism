Player * RankManager::getOrUpdateScoreFromFile(Player *player, std::string filename) {

	ifstream stream(filename);

	std::string contents, line("\n");
	string name, password;
	//int score, firstDelim, secondDelim, temp;
	//Player * newPlayer = new Player;
	//newPlayer->setUserName(player->getUserName());
	while (std::getline(stream, line))
	{
		if (line.size() > 0) {
			//RankManager::createPlayerFromScoreFile(line, newPlayer);
			RankManager::createPlayerFromScoreFile(line, player);
		}
	}
	stream.close();
	//cout <<endl << newPlayer->toString()<< endl;
	//return newPlayer;
	return player;
}