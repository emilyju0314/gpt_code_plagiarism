void RankManager::setRankingsToFile(vector<Player*> *players, std::string filename) {
	ofstream stream;
	stream.open(filename);

	for (Player* p : *players)
	{
		stream << endl << p->getRankFileContent() << endl;
	}

	stream.close();
}