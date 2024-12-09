static void PrepareGroupsForSimultaneousArrival()
{
	GROUP& first_group = *gpPendingSimultaneousGroup;

	/* For all of the groups that haven't arrived yet, determine which one is
	 * going to take the longest. */
	UINT32 latest_arrival_time = 0;
	FOR_EACH_PLAYER_GROUP(i)
	{
		GROUP& g = *i;
		if (&g == &first_group)                 continue;
		if (!g.fBetweenSectors)                 continue;
		if (g.ubNextX != first_group.ubSectorX) continue;
		if (g.ubNextY != first_group.ubSectorY) continue;
		if (IsGroupTheHelicopterGroup(g))       continue;
		latest_arrival_time = MAX(g.uiArrivalTime, latest_arrival_time);
		g.uiFlags |= GROUPFLAG_SIMULTANEOUSARRIVAL_APPROVED | GROUPFLAG_MARKER;
	}

	/* Now, go through the list again, and reset their arrival event to the latest
	 * arrival time. */
	FOR_EACH_GROUP(i)
	{
		GROUP& g = *i;
		if (!(g.uiFlags & GROUPFLAG_MARKER)) continue;

		DeleteStrategicEvent(EVENT_GROUP_ARRIVAL, g.ubGroupID);

		/* NOTE: This can cause the arrival time to be > GetWorldTotalMin() +
		 * TraverseTime, so keep that in mind if you have any code that uses these 3
		 * values to figure out how far along its route a group is! */
		g.setArrivalTime(latest_arrival_time);
		AddStrategicEvent(EVENT_GROUP_ARRIVAL, g.uiArrivalTime, g.ubGroupID);

		if (g.fPlayer && g.uiArrivalTime - ABOUT_TO_ARRIVE_DELAY > GetWorldTotalMin())
		{
			AddStrategicEvent(EVENT_GROUP_ABOUT_TO_ARRIVE, g.uiArrivalTime - ABOUT_TO_ARRIVE_DELAY, g.ubGroupID);
		}

		DelayEnemyGroupsIfPathsCross(g);
		g.uiFlags &= ~GROUPFLAG_MARKER;
	}

	/* We still have the first group that has arrived. Because they are set up to
	 * be in the destination sector, we will "warp" them back to the last sector,
	 * and also setup a new arrival time for them. */
	first_group.ubNextX         = first_group.ubSectorX;
	first_group.ubNextY         = first_group.ubSectorY;
	first_group.ubSectorX       = first_group.ubPrevX;
	first_group.ubSectorY       = first_group.ubPrevY;
	first_group.setArrivalTime(latest_arrival_time);
	first_group.fBetweenSectors = TRUE;

	if (first_group.fVehicle)
	{
		VEHICLETYPE& v = GetVehicleFromMvtGroup(first_group);
		v.fBetweenSectors = TRUE;

		if (!IsHelicopter(v))
		{
			SOLDIERTYPE& vs = GetSoldierStructureForVehicle(v);
			vs.fBetweenSectors = TRUE;
		}
	}

	AddStrategicEvent(EVENT_GROUP_ARRIVAL, first_group.uiArrivalTime, first_group.ubGroupID);

	if (first_group.fPlayer && first_group.uiArrivalTime - ABOUT_TO_ARRIVE_DELAY > GetWorldTotalMin())
	{
		AddStrategicEvent(EVENT_GROUP_ABOUT_TO_ARRIVE, first_group.uiArrivalTime - ABOUT_TO_ARRIVE_DELAY, first_group.ubGroupID);
	}
	DelayEnemyGroupsIfPathsCross(first_group);
}