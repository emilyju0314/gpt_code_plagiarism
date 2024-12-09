Item *Character::getItem(char *itemName)
{
	if(m_pBattleItems->getItem(itemName) != NULL)
		return m_pBattleItems->getItem(itemName);
	else
		return m_pTreasureItems->getItem(itemName);
}