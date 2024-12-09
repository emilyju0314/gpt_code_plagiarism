void ReplaceObsoleteRoads()
{
	INT32 i;
	INT32 iMacro;
	LEVELNODE *pObject;
	BOOLEAN fRoadExistsAtGridNo;
	for( i = 0; i < WORLD_MAX; i++ )
	{
		pObject = gpWorldLevelData[ i ].pObjectHead;
		fRoadExistsAtGridNo = FALSE;
		while( pObject )
		{
			if( pObject->usIndex >= FIRSTROAD1 && pObject->usIndex <= FIRSTROAD32 )
			{
				fRoadExistsAtGridNo = TRUE;
				iMacro = pObject->usIndex - FIRSTROAD1;
				PlaceRoadMacroAtGridNo( i, iMacro );
			}
			pObject = pObject->pNext;
		}
		if( fRoadExistsAtGridNo )
		{
			RemoveAllObjectsOfTypeRange( i, FIRSTROAD, FIRSTROAD );
		}
	}
}