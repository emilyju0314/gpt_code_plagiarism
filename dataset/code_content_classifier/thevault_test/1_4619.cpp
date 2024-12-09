void RankManager::sortAndRankPlayers(vector<Player*> *players) {
	//Player * plys = players->data();
	const int SIZE = players->size();
	int maxIndex = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		maxIndex = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (players->at(i)->getScore() < players->at(j)->getScore()) {
				maxIndex = j;
			}
		}

		if (maxIndex != i) {

			iter_swap(players->begin() + i, players->begin() + maxIndex);
		}

	}

}