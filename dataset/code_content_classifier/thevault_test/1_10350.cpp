Character::~Character() {
	
	delete[] m_iCharacterTraits;

	delete m_pBattleItems;
	delete m_pTreasureItems;

	//cout << "Now executing Character destructor." << endl;
}