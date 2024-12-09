void RankManager::getRankingsFromFile(vector<Player*> *players, std::string filename) {
	ifstream stream(filename);

	std::string contents, line("\n");
	string name, userName;

	while (std::getline(stream, line))
	{
		if (line.size() > 0) {
			userName = line.substr(0, line.find(Player::RANK_FILE_DELIM));
			name = line.substr(line.find(Player::RANK_FILE_DELIM) + Player::RANK_FILE_DELIM.size(), line.size());
			players->push_back(new Player(userName, name, "****", 0));
		}
	}

	stream.close();
}