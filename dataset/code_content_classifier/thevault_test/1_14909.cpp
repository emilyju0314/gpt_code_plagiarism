static RefuelSite const* FindClosestRefuelSite(bool const must_be_available)
{
	INT32             shortest_distance = 9999;
	RefuelSite const* closest_site      = 0;

	VEHICLETYPE const& v        				= GetHelicopter();
	INT16 sectorID											= CALCULATE_STRATEGIC_INDEX(v.sSectorX , v.sSectorY);
	GROUP& g														= *GetGroup(v.ubMovementGroup);
	// find shortest distance to refuel site
	for (INT32 i = 0; i < NUMBER_OF_REFUEL_SITES; ++i)
	{
		// if this refuelling site is available
		if (!fRefuelingSiteAvailable[i] && must_be_available) continue;

		// find if sector is under control, find distance from heli to it
		RefuelSite  const& r        = g_refuel_site[i];
		INT16       const  dest     = r.sector;
		INT32       const  distance = FindStratPath( sectorID, dest, g, FALSE);
		if (distance >= shortest_distance) continue;

		// shorter, copy over
		shortest_distance = distance;
		closest_site      = &r;
	}
	return closest_site;
}