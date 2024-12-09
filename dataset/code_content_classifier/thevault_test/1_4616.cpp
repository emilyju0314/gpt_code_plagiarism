Player* RankManager::userExist(vector<Player*> players, string username) {
	for (Player *p : players) {
		if (username.compare(p->getUserName()) == 0) {
			return p;
		}
	}
	return nullptr;
}