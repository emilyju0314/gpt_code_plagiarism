Item *Character::dropItem(char *itemName)
{
	
	Item *returnItem;

	returnItem = m_pBattleItems->dropItem(itemName);

	if(returnItem != NULL)
		return returnItem;
	else
		return m_pTreasureItems->dropItem(itemName);

    //return NULL;
}