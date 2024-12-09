static void PasteHigherTexture(UINT32 iMapIndex, UINT32 fNewType)
{
	UINT8  ubLastHighLevel;
	std::vector<UINT32> deletedTypes;

	// Here we do the following:
	// - Remove old type from layer
	// - Smooth World with old type
	// - Add a 3 by 3 square of new type at head
	// - Smooth World with new type

	//if (iMapIndex < GRIDSIZE && TypeRangeExistsInLandLayer(iMapIndex, FIRSTFLOOR, LASTFLOOR))
	//ATE: DONOT DO THIS!!!!!!! - I know what was intended - not to draw over floors - this
	// I don't know is the right way to do it!
		//return;


	if ( iMapIndex < GRIDSIZE && AnyHeigherLand( iMapIndex, fNewType, &ubLastHighLevel ))
	{
		AddToUndoList( iMapIndex );

		// - For all heigher level, remove
		RemoveHigherLandLevels(iMapIndex, fNewType, deletedTypes);

		// Set with a radius of 1 and smooth according to height difference
		SetLowerLandIndexWithRadius( iMapIndex, fNewType, 1 , TRUE );

		// Smooth all deleted levels
		for (UINT32 deletedType : deletedTypes)
		{
			SmoothTerrainRadius( iMapIndex, deletedType, 1, TRUE );
		}
	}
	else if ( iMapIndex < GRIDSIZE )
	{
		AddToUndoList( iMapIndex );

		UINT16 NewTile = GetTileIndexFromTypeSubIndex(fNewType, REQUIRES_SMOOTHING_TILE);
		SetLandIndex(iMapIndex, NewTile, fNewType);

		// Smooth item then adding here
		SmoothTerrain( iMapIndex, fNewType, &NewTile, FALSE );

		if ( NewTile != NO_TILE )
		{
			// Change tile
			SetLandIndex(iMapIndex, NewTile, fNewType);
		}
	}
}