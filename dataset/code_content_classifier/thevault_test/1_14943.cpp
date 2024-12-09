static void BuildSlantRoof(INT32 iLeft, INT32 iTop, INT32 iRight, INT32 iBottom, UINT16 usWallType, UINT16 usRoofType, BOOLEAN fVertical)
{
	INT32 i;
	INT32 iMapIndex;
	if( fVertical )
	{
		iMapIndex = iBottom * WORLD_COLS + iLeft;
		//This happens to be the only mapindex that needs to be backed up.  The rest have already been
		//done because of the building code before this.
		AddToUndoList( iMapIndex + 8 );
		//Add the closest viewable pieces.  There are two aframe walls pieces, and extended aframe roof pieces.
		UINT16 usTileIndex;
		usTileIndex = GetTileIndexFromTypeSubIndex(usWallType, VWALL_LEFT);
		AddRoofToHead( iMapIndex + 4, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usWallType, VWALL_RIGHT);
		AddRoofToHead( iMapIndex + 8, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_LEFT);
		AddRoofToHead( iMapIndex + 3, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_RIGHT);
		AddRoofToHead( iMapIndex + 7, usTileIndex );
		for( i = iBottom - 1; i > iTop; i-- )
		{
			iMapIndex -= WORLD_COLS;
			usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THIN_LEFT);
			AddRoofToHead( iMapIndex + 3, usTileIndex );
			usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THIN_RIGHT);
			AddRoofToHead( iMapIndex + 7, usTileIndex );
		}
		iMapIndex -= WORLD_COLS;
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_LEFT);
		AddRoofToHead( iMapIndex + 3, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_RIGHT);
		AddRoofToHead( iMapIndex + 7, usTileIndex );
	}
	else
	{
		iMapIndex = iTop * WORLD_COLS + iRight;
		//This happens to be the only mapindex that needs to be backed up.  The rest have already been
		//done because of the building code before this.
		AddToUndoList( iMapIndex + 8*WORLD_COLS );
		//Add the closest viewable pieces.  There are two aframe walls pieces, and extended aframe roof pieces.
		UINT16 usTileIndex;
		usTileIndex = GetTileIndexFromTypeSubIndex(usWallType, HWALL_LEFT);
		AddRoofToHead( iMapIndex + 4*WORLD_COLS, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usWallType, HWALL_RIGHT);
		AddRoofToHead( iMapIndex + 8*WORLD_COLS, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_TOP);
		AddRoofToHead( iMapIndex + 3*WORLD_COLS, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_BOTTOM);
		AddRoofToHead( iMapIndex + 7*WORLD_COLS, usTileIndex );
		for( i = iRight - 1; i > iLeft; i-- )
		{
			iMapIndex--;
			usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THIN_TOP);
			AddRoofToHead( iMapIndex + 3*WORLD_COLS, usTileIndex );
			usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THIN_BOTTOM);
			AddRoofToHead( iMapIndex + 7*WORLD_COLS, usTileIndex );
		}
		iMapIndex--;
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_TOP);
		AddRoofToHead( iMapIndex + 3*WORLD_COLS, usTileIndex );
		usTileIndex = GetTileIndexFromTypeSubIndex(usRoofType, THICK_BOTTOM);
		AddRoofToHead( iMapIndex + 7*WORLD_COLS, usTileIndex );
	}
}