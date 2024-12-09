FOR_EACH_IN_TEAM(pCivSoldier, CIV_TEAM)
	{
		if ( pCivSoldier == pSoldier )
		{
			continue;
		}

		// killer seen by civ?
		if (SoldierToSoldierLineOfSightTest(pCivSoldier, killer, STRAIGHT_RANGE, TRUE) != 0)
		{
			bSeenState |= 1;
		}

		// victim seen by civ?
		if( SoldierToSoldierLineOfSightTest( pCivSoldier, pSoldier, STRAIGHT_RANGE, TRUE ) != 0 )
		{
			bSeenState |= 2;
		}
	}