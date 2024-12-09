static void HandleOtherGroupsArrivingSimultaneously(UINT8 const x, UINT8 const y, UINT8 const z)
{
	UINT32 const now = GetWorldTotalSeconds();
	gubNumGroupsArrivedSimultaneously = 0;
restart:
	for (STRATEGICEVENT* i = gpEventList; i && i->uiTimeStamp <= now; i = i->next)
	{
		if (i->ubCallbackID != EVENT_GROUP_ARRIVAL) continue;
		if (i->ubFlags & SEF_DELETION_PENDING)      continue;

		GROUP& g = *GetGroup((UINT8)i->uiParam);
		if (g.ubNextX != x || g.ubNextY != y || g.ubSectorZ != z) continue;
		if (!g.fBetweenSectors) continue;

		GroupArrivedAtSector(g, FALSE, FALSE);
		g.uiFlags |= GROUPFLAG_GROUP_ARRIVED_SIMULTANEOUSLY;
		++gubNumGroupsArrivedSimultaneously;
		DeleteStrategicEvent(EVENT_GROUP_ARRIVAL, g.ubGroupID);
		goto restart;
	}
}