BOOLEAN IsValidJumpLocation(const SOLDIERTYPE* pSoldier, INT16 sGridNo, BOOLEAN fCheckForPath)
{
	INT16 sSpot, sIntSpot;
	UINT8 sDirs[4] = { NORTH, EAST, SOUTH, WEST };
	UINT8 cnt;
	UINT8 ubMovementCost;

	// First check that action point cost is zero so far
	// ie: NO PATH!
	if ( gsCurrentActionPoints != 0 && fCheckForPath )
	{
		return( FALSE );
	}

	// Loop through positions...
	for (cnt = 0; cnt < 4; cnt++)
	{
		// MOVE OUT TWO DIRECTIONS
		sIntSpot = NewGridNo( sGridNo, DirectionInc( sDirs[ cnt ] ) );

		// ATE: Check our movement costs for going through walls!
		ubMovementCost = gubWorldMovementCosts[ sIntSpot ][ sDirs[ cnt ] ][ pSoldier->bLevel ];
		if ( IS_TRAVELCOST_DOOR( ubMovementCost ) )
		{
			ubMovementCost = DoorTravelCost(pSoldier, sIntSpot, ubMovementCost, pSoldier->bTeam == OUR_TEAM, NULL);
		}

		// If we have hit an obstacle, STOP HERE
		if ( ubMovementCost >= TRAVELCOST_BLOCKED )
		{
			// no good, continue
			continue;
		}


		// TWICE AS FAR!
		sSpot = NewGridNo( sIntSpot, DirectionInc( sDirs[ cnt ] ) );

		// Is the soldier we're looking at here?
		if (WhoIsThere2(sSpot, pSoldier->bLevel) == pSoldier)
		{
			// Double check OK destination......
			if ( NewOKDestination( pSoldier, sGridNo, TRUE, (INT8)gsInterfaceLevel ) )
			{
				// If the soldier in the middle of doing stuff?
				if ( !pSoldier->fTurningUntilDone )
				{
					// OK, NOW check if there is a guy in between us
					const SOLDIERTYPE* const guy_there = WhoIsThere2(sIntSpot, pSoldier->bLevel);

					// Is there a guy and is he prone?
					if (guy_there != NULL &&
						guy_there != pSoldier &&
						gAnimControl[guy_there->usAnimState].ubHeight == ANIM_PRONE)
					{
						// It's a GO!
						return( TRUE );
					}
				}
			}
		}
	}

	return( FALSE );
}