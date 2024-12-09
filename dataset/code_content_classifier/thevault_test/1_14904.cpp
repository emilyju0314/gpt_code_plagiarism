static void CancelEmptyPersistentGroupMovement(GROUP& g)
{
	Assert(g.ubGroupSize == 0);
	Assert(g.fPersistant);

	/* Don't do this for vehicle groups - the chopper can keep flying empty, while
	 * other vehicles still exist and teleport to nearest sector instead */
	if (g.fVehicle) return;

	// Prevent it from arriving empty
	DeleteStrategicEvent(EVENT_GROUP_ARRIVAL, g.ubGroupID);

	RemoveGroupWaypoints(g);
	g.uiTraverseTime  = 0;
	g.setArrivalTime(0);
	g.fBetweenSectors = FALSE;
	g.ubPrevX         = 0;
	g.ubPrevY         = 0;
	g.ubSectorX       = 0;
	g.ubSectorY       = 0;
	g.ubNextX         = 0;
	g.ubNextY         = 0;
}