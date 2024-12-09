Character::Character(char *name, int Class, int Alignment, int HitPoints, int Strength,
             int Dexterity, int Constitution, int Intelligence, int Wisdom,
             int Charisma) {
	
	m_pNext = NULL;
	
	m_iCharacterTraits = new int[6];

	strcpy_s(m_sName, name);
	m_iClass = Class;
	m_iAlignment = Alignment;
	m_iHitPoints = HitPoints;

	m_iCharacterTraits[0] = Strength;
	m_iCharacterTraits[1] = Dexterity;
	m_iCharacterTraits[2] = Constitution;
	m_iCharacterTraits[3] = Intelligence;
	m_iCharacterTraits[4] = Wisdom;
	m_iCharacterTraits[5] = Charisma;

	m_pBattleItems = new Possessions();
	m_pTreasureItems = new Possessions();

	//cout << "Now executing Character constructor." << endl;

	//cout << "Now executing Character parameterized constructor." << endl;
}