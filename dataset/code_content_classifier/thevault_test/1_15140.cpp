void ChangeO3SectorStatue( BOOLEAN fFromExplosion )
{
	EXITGRID ExitGrid;
	UINT16 usTileIndex;

	// Remove old graphic
	{
		ApplyMapChangesToMapTempFile app;
		// Remove it!
		// Get index for it...
		usTileIndex = GetTileIndexFromTypeSubIndex(EIGHTOSTRUCT, 5);
		RemoveStruct( 13830, usTileIndex );

		// Add new one...
		if ( fFromExplosion )
		{
			// Use damaged peice
			usTileIndex = GetTileIndexFromTypeSubIndex(EIGHTOSTRUCT, 7);
		}
		else
		{
			usTileIndex = GetTileIndexFromTypeSubIndex(EIGHTOSTRUCT, 8);
			// Play sound...

			PlayJA2Sample(OPEN_STATUE, HIGHVOLUME, 1, MIDDLEPAN);

		}
		AddStructToHead( 13830, usTileIndex );

		// Add exit grid
		ExitGrid.ubGotoSectorX = 3;
		ExitGrid.ubGotoSectorY = MAP_ROW_O;
		ExitGrid.ubGotoSectorZ = 1;
		ExitGrid.usGridNo = 13037;

		AddExitGridToWorld( 13669, &ExitGrid );
		gpWorldLevelData[ 13669 ].uiFlags |= MAPELEMENT_REVEALED;
	}

	// Re-render the world!
	gTacticalStatus.uiFlags |= NOHIDE_REDUNDENCY;
	// FOR THE NEXT RENDER LOOP, RE-EVALUATE REDUNDENT TILES
	InvalidateWorldRedundency( );
	SetRenderFlags(RENDER_FLAG_FULL);

	RecompileLocalMovementCostsFromRadius( 13830, 5 );
}