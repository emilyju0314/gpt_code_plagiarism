static void EraseFloorOwnedBuildingPieces(UINT32 iMapIndex)
{
	LEVELNODE	*pStruct = NULL;

	if( !gfBasement && !FloorAtGridNo( iMapIndex ) )
	{	//We don't have ownership issues if there isn't a floor here.
		return;
	}
	EraseBuilding( iMapIndex );
	//FIRST, SEARCH AND DESTROY FOR A LEFT NEIGHBORING TILE WITH A TOP_RIGHT ORIENTED WALL
	pStruct = gpWorldLevelData[ iMapIndex - 1 ].pStructHead;
	while( pStruct != NULL )
	{
		if ( pStruct->usIndex != NO_TILE )
		{
			const UINT32 uiTileType = GetTileType(pStruct->usIndex);
			if ( (uiTileType >= FIRSTWALL && uiTileType <= LASTWALL) ||
				(uiTileType >= FIRSTDOOR && uiTileType <= LASTDOOR) )
			{
				UINT16 usWallOrientation = GetWallOrientation(pStruct->usIndex);
				if( usWallOrientation == INSIDE_TOP_RIGHT || usWallOrientation == OUTSIDE_TOP_RIGHT )
				{
					AddToUndoList( iMapIndex - 1 );
					RemoveStruct( iMapIndex - 1, pStruct->usIndex );
					RemoveAllShadowsOfTypeRange( iMapIndex - 1, FIRSTWALL, LASTWALL );
					break; //otherwise, it'll crash because pStruct is toast.
				}
			}
		}
		pStruct = pStruct->pNext;
	}
	//FINALLY, SEARCH AND DESTROY FOR A TOP NEIGHBORING TILE WITH A TOP_LEFT ORIENTED WALL
	pStruct = gpWorldLevelData[ iMapIndex - WORLD_COLS ].pStructHead;
	while( pStruct != NULL )
	{
		if ( pStruct->usIndex != NO_TILE )
		{
			const UINT32 uiTileType = GetTileType(pStruct->usIndex);
			if ( (uiTileType >= FIRSTWALL && uiTileType <= LASTWALL) ||
				(uiTileType >= FIRSTDOOR && uiTileType <= LASTDOOR) )
			{
				UINT16 usWallOrientation = GetWallOrientation(pStruct->usIndex);
				if( usWallOrientation == INSIDE_TOP_LEFT || usWallOrientation == OUTSIDE_TOP_LEFT )
				{
					AddToUndoList( iMapIndex - WORLD_COLS );
					RemoveStruct( iMapIndex - WORLD_COLS , pStruct->usIndex );
					RemoveAllShadowsOfTypeRange( iMapIndex - WORLD_COLS, FIRSTWALL, LASTWALL );
					break; //otherwise, it'll crash because pStruct is toast.
				}
			}
		}
		pStruct = pStruct->pNext;
	}
}