void RetreatGroupToPreviousSector(GROUP& g)
{
	AssertMsg(!g.fBetweenSectors, "Can't retreat a group when between sectors!");

	UINT8 direction = 255;
	if (g.ubPrevX != 16 || g.ubPrevY != 16)
	{ // Group has a previous sector
		g.ubNextX = g.ubPrevX;
		g.ubNextY = g.ubPrevY;

		// Determine the correct direction
		INT32 const dx = g.ubNextX - g.ubSectorX;
		INT32 const dy = g.ubNextY - g.ubSectorY;
		if      (dx ==  0 && dy == -1) direction = NORTH_STRATEGIC_MOVE;
		else if (dx ==  1 && dy ==  0) direction = EAST_STRATEGIC_MOVE;
		else if (dx ==  0 && dy ==  1) direction = SOUTH_STRATEGIC_MOVE;
		else if (dx == -1 && dy ==  0) direction = WEST_STRATEGIC_MOVE;
		else
		{
			throw std::runtime_error(ST::format("Player group attempting illegal retreat from {}{} to {}{}.", (char)(g.ubSectorY + 'A' - 1), g.ubSectorX, (char)(g.ubNextY + 'A' - 1), g.ubNextX).to_std_string());
		}
	}
	else
	{ // Group doesn't have a previous sector. Create one, then recurse
		CalculateGroupRetreatSector(&g);
		RetreatGroupToPreviousSector(g);
		// XXX direction is invalid, causes out-of-bounds access below
	}

	// Calc time to get to next waypoint
	UINT8 const sector = SECTOR(g.ubSectorX, g.ubSectorY);
	g.uiTraverseTime = GetSectorMvtTimeForGroup(sector, direction, &g);
	AssertMsg(g.uiTraverseTime != TRAVERSE_TIME_IMPOSSIBLE, String("Group %d (%s) attempting illegal move from %c%d to %c%d (%s).", g.ubGroupID, g.fPlayer ? "Player" : "AI", g.ubSectorY + 'A', g.ubSectorX, g.ubNextY + 'A', g.ubNextX, gszTerrain[SectorInfo[sector].ubTraversability[direction]]));

	// Because we are in the strategic layer, don't make the arrival instantaneous (towns)
	if (g.uiTraverseTime == 0) g.uiTraverseTime = 5;

	g.setArrivalTime(GetWorldTotalMin() + g.uiTraverseTime);
	g.fBetweenSectors = TRUE;
	g.uiFlags        |= GROUPFLAG_JUST_RETREATED_FROM_BATTLE;

	if (g.fVehicle)
	{ // Vehicle, set fact it is between sectors too
		VEHICLETYPE& v = GetVehicleFromMvtGroup(g);
		v.fBetweenSectors = TRUE;
	}

	if (!AddStrategicEvent(EVENT_GROUP_ARRIVAL, g.uiArrivalTime, g.ubGroupID))
		SLOGA("Failed to add movement event.");

	// For the case of player groups, we need to update the information of the soldiers.
	if (g.fPlayer)
	{
		if (g.uiArrivalTime - ABOUT_TO_ARRIVE_DELAY > GetWorldTotalMin())
		{
			AddStrategicEvent(EVENT_GROUP_ABOUT_TO_ARRIVE, g.uiArrivalTime - ABOUT_TO_ARRIVE_DELAY, g.ubGroupID);
		}

		CFOR_EACH_PLAYER_IN_GROUP(i, &g)
		{
			SOLDIERTYPE& s = *i->pSoldier;
			s.fBetweenSectors = TRUE;
			RemoveSoldierFromTacticalSector(s);
		}
	}
}