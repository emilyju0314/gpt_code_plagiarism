static BOOLEAN SetLowerLandIndexWithRadius(INT32 iMapIndex, UINT32 uiNewType, UINT8 ubRadius, BOOLEAN fReplace)
{
	INT16   sTop, sBottom;
	INT16   sLeft, sRight;
	INT16   cnt1, cnt2;
	INT32   iNewIndex;
	BOOLEAN fDoPaste = FALSE;
	INT32   leftmost;
	UINT8   ubLastHighLevel;
	std::vector<UINT32> smoothTiles;
	UINT16  usTemp;

	// Determine start end end indicies and num rows
	sTop		= ubRadius;
	sBottom = -ubRadius;
	sLeft   = - ubRadius;
	sRight  = ubRadius;

	if ( iMapIndex >= GRIDSIZE )
		return ( FALSE );

	for( cnt1 = sBottom; cnt1 <= sTop; cnt1++ )
	{

		leftmost = ( ( iMapIndex + ( WORLD_COLS * cnt1 ) )/ WORLD_COLS ) * WORLD_COLS;

		for( cnt2 = sLeft; cnt2 <= sRight; cnt2++ )
		{
			iNewIndex = iMapIndex + ( WORLD_COLS * cnt1 ) + cnt2;

			if ( iNewIndex >=0 && iNewIndex < WORLD_MAX &&
				iNewIndex >= leftmost && iNewIndex < ( leftmost + WORLD_COLS ) )
			{

				if ( fReplace )
				{
					fDoPaste = TRUE;
				}
				else
				{
					if (FindTypeInLandLayer(iNewIndex, uiNewType))
					{
						fDoPaste = TRUE;
					}
				}

				//if (fDoPaste && !TypeRangeExistsInLandLayer(iMapIndex, FIRSTFLOOR, LASTFLOOR))
				if ( fDoPaste  )
				{
					if ( iMapIndex == iNewIndex )
					{
						AddToUndoList( iMapIndex );

						// Force middle one to NOT smooth, and set to random 'full' tile
						usTemp = Random(10) + 1;
						UINT16 NewTile = GetTileIndexFromTypeSubIndex(uiNewType, usTemp);
						SetLandIndex(iNewIndex, NewTile, uiNewType);
					}
					else if ( AnyHeigherLand( iNewIndex, uiNewType, &ubLastHighLevel ) )
					{
						AddToUndoList( iMapIndex );

						// Force middle one to NOT smooth, and set to random 'full' tile
						usTemp = Random(10) + 1;
						UINT16 NewTile = GetTileIndexFromTypeSubIndex(uiNewType, usTemp);
						SetLandIndex(iNewIndex, NewTile, uiNewType);
					}
					else
					{
						AddToUndoList( iMapIndex );

						// Set tile to 'smooth target' tile
						UINT16 NewTile = GetTileIndexFromTypeSubIndex(uiNewType, REQUIRES_SMOOTHING_TILE);
						SetLandIndex(iNewIndex, NewTile, uiNewType);

						// If we are top-most, add to smooth list
						smoothTiles.push_back(iNewIndex);
					}
				}
			}
		}
	}

	// Once here, smooth any tiles that need it
	for (UINT32 smoothTile : smoothTiles)
	{
		SmoothTerrainRadius(smoothTile, uiNewType, 10, FALSE);
	}

	return( TRUE );
}