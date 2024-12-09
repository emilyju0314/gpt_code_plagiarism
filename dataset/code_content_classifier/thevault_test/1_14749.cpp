void AddExclusiveShadow(UINT32 iMapIndex, UINT16 usIndex)
{
	for (LEVELNODE* pShadow = gpWorldLevelData[iMapIndex].pShadowHead; pShadow; pShadow = pShadow->pNext)
	{
		if (pShadow->usIndex == usIndex)
			return;
	}
	AddShadowToHead(iMapIndex, usIndex);
}