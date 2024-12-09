BOOLEAN ReplaceStructIndex(UINT32 iMapIndex, UINT16 usOldIndex, UINT16 usNewIndex)
{
	RemoveStruct(iMapIndex, usOldIndex);
	AddWallToStructLayer(iMapIndex, usNewIndex, FALSE);
	return TRUE;
//	LEVELNODE	*pStruct				= NULL;
//	pStruct = gpWorldLevelData[ iMapIndex ].pStructHead;
// Look through all Structs and remove index if found
//	while( pStruct != NULL )
//	{
//		if ( pStruct->usIndex == usOldIndex )
//		{
//			// OK, set new index value
//			pStruct->usIndex = usNewIndex;
//			AdjustForFullTile( iMapIndex );
//			return( TRUE );
//		}
//		// Advance
//		pStruct = pStruct->pNext;
//	}
//	// Could not find it, return FALSE
//	return( FALSE );
}