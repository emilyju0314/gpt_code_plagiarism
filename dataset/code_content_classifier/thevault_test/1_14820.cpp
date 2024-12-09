CFOR_EACH_IN_TEAM(i, OUR_TEAM)
	{
		SOLDIERTYPE const& s = *i;
		/* ARM: Now allows loading of sector with all mercs below OKLIFE as long as
		 * they're alive */
		if (s.bLife == 0)                      continue;
		if (s.uiStatusFlags & SOLDIER_VEHICLE) continue;
		if (s.bAssignment == IN_TRANSIT)       continue;
		if (s.bAssignment == ASSIGNMENT_POW)   continue;
		if (s.bAssignment == ASSIGNMENT_DEAD)  continue;
		if (SoldierAboardAirborneHeli(s))      continue;
		if (s.fBetweenSectors)                 continue;
		if (s.sSectorX != x)                   continue;
		if (s.sSectorY != y)                   continue;
		if (s.bSectorZ != z)                   continue;
		return true;
	}