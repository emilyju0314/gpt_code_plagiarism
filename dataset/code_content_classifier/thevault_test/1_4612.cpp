void RankManager::loadPlayerInfoComplete() {
	int i = 0;
	getRankingsFromFile(playersInMem, ranksFile);
	for (Player *p : *playersInMem) {
		completelUserScoresFileName = partialUserScoresFileName + p->getUserName() + fileExtention;
		//cout << endl << "Loaded: " << completelUserScoresFileName << "from storage" << endl;

		getOrUpdateScoreFromFile(p, completelUserScoresFileName);
		//cout << endl << p.toString() << endl;

	}
}