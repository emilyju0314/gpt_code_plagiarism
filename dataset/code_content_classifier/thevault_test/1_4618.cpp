void RankManager::setOrUpdateScoreToFile(Player *player, std::string filename) {
	ofstream stream;

	stream.open(filename);
	stream << endl << player->getScoreFileContent() << endl;

	stream.close();
}