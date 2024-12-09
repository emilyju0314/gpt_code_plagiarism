bool Character::addItem(Item *item)
{

	if(item->m_iType == 1)
		return m_pBattleItems->addItem(item);
	else
		return m_pTreasureItems->addItem(item);

}