void RemoveBuildingSectionFromWorld( SGPRect *pSelectRegion )
{
	UINT32 top, left, right, bottom, x, y;
	UINT32 iMapIndex;
	UINT16 usFloorType;
	BOOLEAN fFloor;

	top = pSelectRegion->iTop;
	left = pSelectRegion->iLeft;
	right = pSelectRegion->iRight;
	bottom = pSelectRegion->iBottom;

	//1ST PASS:  Erase all building owned by the floor tile if there is one.
	for( y = top; y <= bottom; y++ ) for( x = left; x <= right; x++ )
	{
		iMapIndex = y * WORLD_COLS + x;
		EraseFloorOwnedBuildingPieces( iMapIndex ); //Erase possible top and left walls in bordering tiles.
	}
	//2ND PASS:  Build new walls whereever there are neighboring floor tiles.
	for( y = top; y <= bottom; y++ ) for( x = left; x <= right; x++ )
	{
		iMapIndex = y * WORLD_COLS + x;
		//NOTE:  Top and bottom walls MUST be placed first -- it minimizes the number of special cases.
		if( y == top )
		{
			fFloor = FloorAtGridNo( iMapIndex - WORLD_COLS );
			if( (gfBasement && !fFloor) || (!gfBasement && fFloor && !GetHorizontalWall( iMapIndex - WORLD_COLS )) )
				BuildWallPiece( iMapIndex, EXTERIOR_TOP, 0 );
		}
		if( y == bottom )
		{
			fFloor = FloorAtGridNo( iMapIndex + WORLD_COLS );
			if( (gfBasement && !fFloor) || (!gfBasement && fFloor && !GetHorizontalWall( iMapIndex )) )
				BuildWallPiece( iMapIndex, EXTERIOR_BOTTOM, 0 );
		}
		if( x == left )
		{
			fFloor = FloorAtGridNo( iMapIndex - 1 );
			if( (gfBasement && !fFloor) || (!gfBasement && fFloor && !GetVerticalWall( iMapIndex - 1 )) )
				BuildWallPiece( iMapIndex, EXTERIOR_LEFT, 0 );
		}
		if( x == right )
		{
			fFloor = FloorAtGridNo( iMapIndex + 1);
			if( (gfBasement && !fFloor) || (!gfBasement && fFloor && !GetVerticalWall( iMapIndex )) )
				BuildWallPiece( iMapIndex, EXTERIOR_RIGHT, 0 );
		}
	}
	//3RD PASS:  Go around the outside of the region, and rebuild the roof.
	if( gfBasement )
	{
		usFloorType = GetRandomIndexByRange( FIRSTFLOOR, LASTFLOOR );
		if( usFloorType == 0xffff )
			usFloorType = FIRSTFLOOR;
		for( y = top; y <= bottom; y++ ) for( x = left; x <= right; x++ )
		{
			iMapIndex = y * WORLD_COLS + x;
			UINT16 usTileIndex = GetTileIndexFromTypeSubIndex(usFloorType, 1);
			AddLandToHead( iMapIndex, (UINT16)( usTileIndex + Random( FLOOR_VARIANTS ) ) );
		}
	}
	for( y = top - 1; y <= bottom + 1; y++ ) for( x = left - 1; x <= right + 1; x++ )
	{
		iMapIndex = y * WORLD_COLS + x;
		if( y == top - 1 || y == bottom + 1 || x == left - 1 || x == right + 1 )
		{
			if( (!gfBasement && FloorAtGridNo( iMapIndex )) || (gfBasement && !FloorAtGridNo( iMapIndex )) )
			{
				RebuildRoof( iMapIndex, 0 );
			}
		}
	}
}