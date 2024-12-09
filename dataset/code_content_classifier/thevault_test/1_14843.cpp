void PasteDebris( UINT32 iMapIndex )
{
	UINT16				usUseIndex;
	UINT16				usUseObjIndex;
	INT32					iRandSelIndex;

	// Get selection list for debris
	pSelList = SelDebris;
	pNumSelList = &iNumDebrisSelected;

	if ( iMapIndex < GRIDSIZE )
	{
		AddToUndoList( iMapIndex );

		// Remove any debris that is currently at this map location
		if ( gpWorldLevelData[ iMapIndex ].pObjectHead != NULL )
		{
			RemoveAllObjectsOfTypeRange( iMapIndex, ANOTHERDEBRIS, FIRSTPOINTERS - 1 );
		}

		// Get a random debris from current selection
		iRandSelIndex = GetRandomSelection( );
		if ( iRandSelIndex != -1 )
		{
			// Add debris to the world
			usUseIndex = pSelList[ iRandSelIndex ].usIndex;
			usUseObjIndex = (UINT16)pSelList[ iRandSelIndex ].uiObject;

			AddObjectToTail( iMapIndex, (UINT16)(gTileTypeStartIndex[ usUseObjIndex ] + usUseIndex) );
		}
	}
}