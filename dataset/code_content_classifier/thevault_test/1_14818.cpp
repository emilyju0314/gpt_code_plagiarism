BOOLEAN OKForSectorExit( INT8 bExitDirection, UINT16 usAdditionalData, UINT32 *puiTraverseTimeInMinutes )
{
	BOOLEAN     fAtLeastOneMercControllable = FALSE;
	BOOLEAN     fOnlySelectedGuy = FALSE;
	SOLDIERTYPE *pValidSoldier = NULL;
	UINT8       ubReturnVal = FALSE;
	UINT8       ubNumControllableMercs = 0;
	UINT8       ubNumMercs = 0, ubNumEPCs = 0;
	UINT8       ubPlayerControllableMercsInSquad = 0;

	const SOLDIERTYPE* const sel = GetSelectedMan();
	// must have a selected soldier to be allowed to tactically traverse.
	if (sel == NULL) return FALSE;

	/*
	//Exception code for the two sectors in San Mona that are separated by a cliff.  We want to allow strategic
	//traversal, but NOT tactical traversal.  The only way to tactically go from D4 to D5 (or viceversa) is to enter
	//the cave entrance.
	if( gWorldSectorX == 4 && gWorldSectorY == 4 && !gbWorldSectorZ && bExitDirection == EAST_STRATEGIC_MOVE )
	{
		gfInvalidTraversal = TRUE;
		return FALSE;
	}
	if( gWorldSectorX == 5 && gWorldSectorY == 4 && !gbWorldSectorZ && bExitDirection == WEST_STRATEGIC_MOVE )
	{
		gfInvalidTraversal = TRUE;
		return FALSE;
	}
	*/

	gfInvalidTraversal = FALSE;
	gfLoneEPCAttemptingTraversal = FALSE;
	gubLoneMercAttemptingToAbandonEPCs = 0;
	gPotentiallyAbandonedEPC = NULL;

	// Look through all mercs and check if they are within range of east end....
	FOR_EACH_IN_TEAM(pSoldier, OUR_TEAM)
	{
		// If we are controllable
		if (OkControllableMerc(pSoldier) && pSoldier->bAssignment == CurrentSquad())
		{
			//Need to keep a copy of a good soldier, so we can access it later, and
			//not more than once.
			pValidSoldier = pSoldier;

			ubNumControllableMercs++;

			//We need to keep track of the number of EPCs and mercs in this squad.  If we have
			//only one merc and one or more EPCs, then we can't allow the merc to tactically traverse,
			//if he is the only merc near enough to traverse.
			if( AM_AN_EPC( pSoldier ) )
			{
				ubNumEPCs++;
				//Also record the EPC's slot ID incase we later build a string using the EPC's name.
				gPotentiallyAbandonedEPC = pSoldier;
				if( AM_A_ROBOT( pSoldier ) && !CanRobotBeControlled( pSoldier ) )
				{
					gfRobotWithoutControllerAttemptingTraversal = TRUE;
					ubNumControllableMercs--;
					continue;
				}
			}
			else
			{
				ubNumMercs++;
			}

			if ( SoldierOKForSectorExit( pSoldier, bExitDirection, usAdditionalData ) )
			{
				fAtLeastOneMercControllable++;

				if (pSoldier == sel) fOnlySelectedGuy = TRUE;
			}
			else
			{
				GROUP *pGroup;

				// ATE: Dont's assume exit grids here...
				if ( bExitDirection != -1 )
				{
					//Now, determine if this is a valid path.
					pGroup = GetGroup( pValidSoldier->ubGroupID );
					AssertMsg( pGroup, String( "%s is not in a valid group (pSoldier->ubGroupID is %d)", pValidSoldier->name.c_str(), pValidSoldier->ubGroupID) );
					UINT32 traverse_time = TRAVERSE_TIME_IMPOSSIBLE;
					if( !gbWorldSectorZ )
					{
						traverse_time = GetSectorMvtTimeForGroup((UINT8)SECTOR(pGroup->ubSectorX, pGroup->ubSectorY), bExitDirection, pGroup);
					}
					else if( gbWorldSectorZ > 1 )
					{ //We are attempting to traverse in an underground environment.  We need to use a complete different
						//method.  When underground, all sectors are instantly adjacent.
						traverse_time = UndergroundTacticalTraversalTime(bExitDirection);
					}
					if (puiTraverseTimeInMinutes) *puiTraverseTimeInMinutes = traverse_time;
					if (traverse_time == TRAVERSE_TIME_IMPOSSIBLE)
					{
						gfInvalidTraversal = TRUE;
						return FALSE;
					}
				}
				else
				{
					// Exit grid travel is instantaneous
					if (puiTraverseTimeInMinutes) *puiTraverseTimeInMinutes = 0;
				}
			}
		}
	}

	// If we are here, at least one guy is controllable in this sector, at least he can go!
	if( fAtLeastOneMercControllable )
	{
		ubPlayerControllableMercsInSquad = (UINT8)NumberOfPlayerControllableMercsInSquad(sel->bAssignment);
		if( fAtLeastOneMercControllable <= ubPlayerControllableMercsInSquad )
		{ //if the selected merc is an EPC and we can only leave with that merc, then prevent it
			//as EPCs aren't allowed to leave by themselves.  Instead of restricting this in the
			//exiting sector gui, we restrict it by explaining it with a message box.
			if (AM_AN_EPC(sel))
			{
				if (fAtLeastOneMercControllable < ubPlayerControllableMercsInSquad || fAtLeastOneMercControllable == 1)
				{
					gfLoneEPCAttemptingTraversal = TRUE;
					return FALSE;
				}
			}
			else
			{	//We previously counted the number of EPCs and mercs, and if the selected merc is not an EPC and there are no
				//other mercs in the squad able to escort the EPCs, we will prohibit this merc from tactically traversing.
				if( ubNumEPCs && ubNumMercs == 1 && fAtLeastOneMercControllable < ubPlayerControllableMercsInSquad )
				{
					gubLoneMercAttemptingToAbandonEPCs = ubNumEPCs;
					return FALSE;
				}
			}
		}
		if ( bExitDirection != -1 )
		{
			GROUP *pGroup;
			//Now, determine if this is a valid path.
			pGroup = GetGroup( pValidSoldier->ubGroupID );
			AssertMsg( pGroup, String( "%s is not in a valid group (pSoldier->ubGroupID is %d)", pValidSoldier->name.c_str(), pValidSoldier->ubGroupID) );
			UINT32 traverse_time = TRAVERSE_TIME_IMPOSSIBLE; // -XXX Wmaybe-uninitialized : valid default?
			if( !gbWorldSectorZ )
			{
				traverse_time = GetSectorMvtTimeForGroup((UINT8)SECTOR(pGroup->ubSectorX, pGroup->ubSectorY), bExitDirection, pGroup);
			}
			else if( gbWorldSectorZ > 0 )
			{ //We are attempting to traverse in an underground environment.  We need to use a complete different
				//method.  When underground, all sectors are instantly adjacent.
				traverse_time = UndergroundTacticalTraversalTime(bExitDirection);
			}
			if (puiTraverseTimeInMinutes) *puiTraverseTimeInMinutes = traverse_time;
			if (traverse_time == TRAVERSE_TIME_IMPOSSIBLE)
			{
				gfInvalidTraversal = TRUE;
				ubReturnVal = FALSE;
			}
			else
			{
				ubReturnVal = TRUE;
			}
		}
		else
		{
			ubReturnVal = TRUE;
			// Exit grid travel is instantaneous
			if (puiTraverseTimeInMinutes) *puiTraverseTimeInMinutes = 0;
		}
	}

	if ( ubReturnVal )
	{
		// Default to FALSE again, until we see that we have
		ubReturnVal = FALSE;

		if ( fAtLeastOneMercControllable )
		{
			// Do we contain the selected guy?
			if ( fOnlySelectedGuy )
			{
				ubReturnVal = 1;
			}
			// Is the whole squad able to go here?
			if ( fAtLeastOneMercControllable == ubPlayerControllableMercsInSquad )
			{
				ubReturnVal = 2;
			}
		}
	}

	return( ubReturnVal );
}