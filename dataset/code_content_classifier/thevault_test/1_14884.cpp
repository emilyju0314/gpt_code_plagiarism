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