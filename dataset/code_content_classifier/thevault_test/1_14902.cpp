BOOLEAN GroupWillMoveThroughSector( GROUP *pGroup, UINT8 ubSectorX, UINT8 ubSectorY )
{
	WAYPOINT *wp;
	INT32 i, dx, dy;
	UINT8 ubOrigX, ubOrigY;

	Assert( pGroup );
	AssertMsg( pGroup->ubMoveType == ONE_WAY, String( "GroupWillMoveThroughSector() -- Attempting to test group with an invalid move type.  ubGroupID: %d, ubMoveType: %d, sector: %c%d -- KM:0",
			pGroup->ubGroupID, pGroup->ubMoveType, pGroup->ubSectorY + 'A' - 1, pGroup->ubSectorX ) );

	//Preserve the original sector values, as we will be temporarily modifying the group's ubSectorX/Y values
	//as we traverse the waypoints.
	ubOrigX = pGroup->ubSectorX;
	ubOrigY = pGroup->ubSectorY;

	i = pGroup->ubNextWaypointID;
	wp = pGroup->pWaypoints;

	if( !wp )
	{ //This is a floating group!?
		return FALSE;
	}
	while( i-- )
	{ //Traverse through the waypoint list to the next waypoint ID
		Assert( wp );
		wp = wp->next;
	}
	Assert( wp );


	while( wp )
	{
		while( pGroup->ubSectorX != wp->x || pGroup->ubSectorY != wp->y )
		{
			//We now have the correct waypoint.
			//Analyse the group and determine which direction it will move from the current sector.
			dx = wp->x - pGroup->ubSectorX;
			dy = wp->y - pGroup->ubSectorY;
			if( dx && dy )
			{ //Can't move diagonally!
				SLOGA("GroupWillMoveThroughSector() -- Attempting to process waypoint in a diagonal direction from sector %c%d to sector %c%d for group at sector %c%d",
					pGroup->ubSectorY + 'A', pGroup->ubSectorX, wp->y + 'A' - 1, wp->x, ubOrigY + 'A' - 1, ubOrigX);
				pGroup->ubSectorX = ubOrigX;
				pGroup->ubSectorY = ubOrigY;
				return TRUE;
			}
			if( !dx && !dy ) //Can't move to position currently at!
			{
				SLOGA("GroupWillMoveThroughSector() -- Attempting to process same waypoint at %c%d for group at %c%d",
					wp->y + 'A' - 1, wp->x, ubOrigY + 'A' - 1, ubOrigX);
				pGroup->ubSectorX = ubOrigX;
				pGroup->ubSectorY = ubOrigY;
				return TRUE;
			}
			//Clip dx/dy value so that the move is for only one sector.
			if( dx >= 1 )
			{
				dx = 1;
			}
			else if( dy >= 1 )
			{
				dy = 1;
			}
			else if( dx <= -1 )
			{
				dx = -1;
			}
			else if( dy <= -1 )
			{
				dy = -1;
			}
			//Advance the sector value
			pGroup->ubSectorX = (UINT8)( dx + pGroup->ubSectorX );
			pGroup->ubSectorY = (UINT8)( dy + pGroup->ubSectorY );
			//Check to see if it the sector we are checking to see if this group will be moving through.
			if( pGroup->ubSectorX == ubSectorX && pGroup->ubSectorY == ubSectorY )
			{
				pGroup->ubSectorX = ubOrigX;
				pGroup->ubSectorY = ubOrigY;
				return TRUE;
			}
		}
		//Advance to the next waypoint.
		wp = wp->next;
	}
	pGroup->ubSectorX = ubOrigX;
	pGroup->ubSectorY = ubOrigY;
	return FALSE;
}