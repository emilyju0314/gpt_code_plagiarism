void CalculateNextMoveIntention( GROUP *pGroup )
{
	INT32 i;
	WAYPOINT *wp;

	Assert( pGroup );

	//TEMP:  Ignore resting...

	//Should be surely an enemy group that has just made a new decision to go elsewhere!
	if( pGroup->fBetweenSectors )
	{
		return;
	}

	if( !pGroup->pWaypoints )
	{
		return;
	}

	//Determine if we are at a waypoint.
	i = pGroup->ubNextWaypointID;
	wp = pGroup->pWaypoints;
	while( i-- )
	{ //Traverse through the waypoint list to the next waypoint ID
		Assert( wp );
		wp = wp->next;
	}
	Assert( wp );

	//We have the next waypoint, now check if we are actually there.
	if( pGroup->ubSectorX == wp->x && pGroup->ubSectorY == wp->y )
	{ //We have reached the next waypoint, so now determine what the next waypoint is.
		switch( pGroup->ubMoveType )
		{
			case ONE_WAY:
				if( !wp->next )
				{ //No more waypoints, so we've reached the destination.
					return;
				}
				//Advance destination to next waypoint ID
				pGroup->ubNextWaypointID++;
				break;
			case CIRCULAR:
				wp = wp->next;
				if( !wp )
				{	//reached the end of the patrol route.  Set to the first waypoint in list, indefinately.
					//NOTE:  If the last waypoint isn't exclusively aligned to the x or y axis of the first
					//			 waypoint, there will be an assertion failure inside the waypoint movement code.
					pGroup->ubNextWaypointID = 0;
				}
				else
					pGroup->ubNextWaypointID++;
				break;
			case ENDTOEND_FORWARDS:
				wp = wp->next;
				if( !wp )
				{
					AssertMsg( pGroup->ubNextWaypointID, "EndToEnd patrol group needs more than one waypoint!" );
					pGroup->ubNextWaypointID--;
					pGroup->ubMoveType = ENDTOEND_BACKWARDS;
				}
				else
					pGroup->ubNextWaypointID++;
				break;
			case ENDTOEND_BACKWARDS:
				if( !pGroup->ubNextWaypointID )
				{
					pGroup->ubNextWaypointID++;
					pGroup->ubMoveType = ENDTOEND_FORWARDS;
				}
				else
					pGroup->ubNextWaypointID--;
				break;
		}
	}
	InitiateGroupMovementToNextSector( pGroup );
}