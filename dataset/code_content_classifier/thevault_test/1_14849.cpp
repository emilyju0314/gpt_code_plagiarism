void PasteBanks(UINT32 const iMapIndex, BOOLEAN const fReplace)
{
	BOOLEAN				fDoPaste = FALSE;
	UINT16				usUseIndex;
	UINT16				usUseObjIndex;

	pSelList = SelBanks;
	pNumSelList = &iNumBanksSelected;

	usUseIndex = pSelList[ iCurBank ].usIndex;
	usUseObjIndex = (UINT16)pSelList[ iCurBank ].uiObject;

	if ( iMapIndex < GRIDSIZE )
	{
		fDoPaste = TRUE;

		if (  gpWorldLevelData[ iMapIndex ].pStructHead != NULL )
		{
				// CHECK IF THE SAME TILE IS HERE
				if ( gpWorldLevelData[ iMapIndex ].pStructHead->usIndex == (UINT16)( gTileTypeStartIndex[ usUseObjIndex ] + usUseIndex ) )
				{
					fDoPaste = FALSE;
				}
		}
		else
		{
			// Nothing is here, paste
			fDoPaste = TRUE;
		}

		if ( fDoPaste )
		{
			AddToUndoList( iMapIndex );

			{
					if ( usUseObjIndex == FIRSTROAD )
					{
						AddObjectToHead( iMapIndex, (UINT16)( gTileTypeStartIndex[ usUseObjIndex ] + usUseIndex ) );
					}
					else
					{
						AddStructToHead( iMapIndex, (UINT16)( gTileTypeStartIndex[ usUseObjIndex ] + usUseIndex ) );
						// Add shadows
						if ( !gfBasement && usUseObjIndex == FIRSTCLIFF )
						{
							//AddShadowToHead( iMapIndex, (UINT16)( gTileTypeStartIndex[ usUseObjIndex - FIRSTCLIFF + FIRSTCLIFFSHADOW ] + usUseIndex ) );
							AddObjectToHead( iMapIndex, (UINT16)( gTileTypeStartIndex[ usUseObjIndex - FIRSTCLIFF + FIRSTCLIFFHANG ] + usUseIndex ) );
						}
					}
			}
		}
	}
}