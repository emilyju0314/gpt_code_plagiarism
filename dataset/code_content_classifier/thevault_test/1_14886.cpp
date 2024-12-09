static void InitiateGroupMovementToNextSector(GROUP* pGroup)
{
	INT32 dx, dy;
	INT32 i;
	UINT8 ubDirection;
	UINT8 ubSector;
	WAYPOINT *wp;
	UINT32 uiSleepMinutes = 0;

	Assert( pGroup );
	i = pGroup->ubNextWaypointID;
	wp = pGroup->pWaypoints;
	while( i-- )
	{ //Traverse through the waypoint list to the next waypoint ID
		Assert( wp );
		wp = wp->next;
	}
	Assert( wp );
	//We now have the correct waypoint.
	//Analyse the group and determine which direction it will move from the current sector.
	dx = wp->x - pGroup->ubSectorX;
	dy = wp->y - pGroup->ubSectorY;
	if( dx && dy )
	{ //Can't move diagonally!
		SLOGA("Attempting to move to waypoint in a diagonal direction from sector %d,%d to sector %d,%d",
			pGroup->ubSectorX, pGroup->ubSectorY, wp->x, wp->y );
	}
	//Clip dx/dy value so that the move is for only one sector.
	if( dx >= 1 )
	{
		ubDirection = EAST_STRATEGIC_MOVE;
		dx = 1;
	}
	else if( dy >= 1 )
	{
		ubDirection = SOUTH_STRATEGIC_MOVE;
		dy = 1;
	}
	else if( dx <= -1 )
	{
		ubDirection = WEST_STRATEGIC_MOVE;
		dx = -1;
	}
	else if( dy <= -1 )
	{
		ubDirection = NORTH_STRATEGIC_MOVE;
		dy = -1;
	}
	else
	{
		SLOGA("InitiateGroupMovementToNextSector: Attempting to move to waypoint %d, %d that you are already at!", wp->x, wp->y);
		return;
	}
	//All conditions for moving to the next waypoint are now good.
	pGroup->ubNextX = (UINT8)( dx + pGroup->ubSectorX );
	pGroup->ubNextY = (UINT8)( dy + pGroup->ubSectorY );
	//Calc time to get to next waypoint...
	ubSector = (UINT8)SECTOR( pGroup->ubSectorX, pGroup->ubSectorY );
	if( !pGroup->ubSectorZ )
	{
		BOOLEAN fCalcRegularTime = TRUE;
		if( !pGroup->fPlayer )
		{ //Determine if the enemy group is "sleeping".  If so, then simply delay their arrival time by the amount of time
			//they are going to be sleeping for.
			if( GetWorldHour() >= 21 || GetWorldHour() <= 4 )
			{ //It is definitely night time.
				if( Chance( 67 ) )
				{ //2 in 3 chance of going to sleep.
					pGroup->uiTraverseTime = GetSectorMvtTimeForGroup( ubSector, ubDirection, pGroup );
					uiSleepMinutes = 360 + Random( 121 ); //6-8 hours sleep
					fCalcRegularTime = FALSE;
				}
			}
		}
		if( fCalcRegularTime )
		{
			pGroup->uiTraverseTime = GetSectorMvtTimeForGroup( ubSector, ubDirection, pGroup );
		}
	}
	else
	{
		pGroup->uiTraverseTime = 1;
	}

	AssertMsg(pGroup->uiTraverseTime != TRAVERSE_TIME_IMPOSSIBLE, String("Group %d (%s) attempting illegal move from %c%d to %c%d (%s).",
			pGroup->ubGroupID, ( pGroup->fPlayer ) ? "Player" : "AI",
			pGroup->ubSectorY+'A', pGroup->ubSectorX, pGroup->ubNextY+'A', pGroup->ubNextX,
			gszTerrain[SectorInfo[ubSector].ubTraversability[ubDirection]] ) );

	// add sleep, if any
	pGroup->uiTraverseTime += uiSleepMinutes;

	if( gfTacticalTraversal && gpTacticalTraversalGroup == pGroup )
	{
		if( gfUndergroundTacticalTraversal )
		{	//underground movement between sectors takes 1 minute.
			pGroup->uiTraverseTime = 1;
		}
		else
		{ //strategic movement between town sectors takes 5 minutes.
			pGroup->uiTraverseTime = 5;
		}
	}

	// if group isn't already between sectors
	if ( !pGroup->fBetweenSectors )
	{
		// put group between sectors
		pGroup->fBetweenSectors	= TRUE;
		// and set it's arrival time
		pGroup->setArrivalTime(GetWorldTotalMin() + pGroup->uiTraverseTime);
	}
	// NOTE: if the group is already between sectors, DON'T MESS WITH ITS ARRIVAL TIME!  THAT'S NOT OUR JOB HERE!!!


	// special override for AI patrol initialization only
	if( gfRandomizingPatrolGroup )
	{ //We're initializing the patrol group, so randomize the enemy groups to have extremely quick and varying
		//arrival times so that their initial positions aren't easily determined.
		pGroup->uiTraverseTime = 1 + Random( pGroup->uiTraverseTime - 1 );
		pGroup->setArrivalTime(GetWorldTotalMin() + pGroup->uiTraverseTime);
	}


	if (pGroup->fVehicle)
	{
		// vehicle, set fact it is between sectors too
		VEHICLETYPE& v = GetVehicleFromMvtGroup(*pGroup);
		v.fBetweenSectors = TRUE;

		if (!IsHelicopter(v))
		{
			SOLDIERTYPE& vs = GetSoldierStructureForVehicle(v);
			vs.fBetweenSectors = TRUE;
			RemoveSoldierFromTacticalSector(vs);
		}
	}

	//Post the event!
	if( !AddStrategicEvent( EVENT_GROUP_ARRIVAL, pGroup->uiArrivalTime, pGroup->ubGroupID ) )
		SLOGA("Failed to add movement event.");

	//For the case of player groups, we need to update the information of the soldiers.
	if( pGroup->fPlayer )
	{
		if( pGroup->uiArrivalTime - ABOUT_TO_ARRIVE_DELAY > GetWorldTotalMin( ) )
		{
			AddStrategicEvent( EVENT_GROUP_ABOUT_TO_ARRIVE, pGroup->uiArrivalTime - ABOUT_TO_ARRIVE_DELAY, pGroup->ubGroupID );
		}

		CFOR_EACH_PLAYER_IN_GROUP(curr, pGroup)
		{
			SOLDIERTYPE& s = *curr->pSoldier;
			s.fBetweenSectors = TRUE;
			RemoveSoldierFromTacticalSector(s);
		}
		CheckAndHandleUnloadingOfCurrentWorld();

		//If an enemy group will be crossing paths with the player group, delay the enemy group's arrival time so that
		//the player will always encounter that group.
		if( !pGroup->ubSectorZ )
		{
			DelayEnemyGroupsIfPathsCross(*pGroup);
		}
	}
}