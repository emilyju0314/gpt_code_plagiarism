vector<Card> Hand::GetCopyOfAllCards() {
	vector<Card> cardcopies;
	for (CardSprite *c : m_vCards) {
		if (c) {
			cardcopies.push_back(Card(*c->GetCard()));
		}
	}
	return cardcopies;
}