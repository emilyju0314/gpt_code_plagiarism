BOOLEAN AddWaypointToPGroup(GROUP* const g, UINT8 const x, UINT8 const y) // Same, but overloaded
{
	AssertMsg(1 <= x && x <= 16, String("AddWaypointToPGroup with out of range sectorX value of %d", x));
	AssertMsg(1 <= y && y <= 16, String("AddWaypointToPGroup with out of range sectorY value of %d", y));

	if (!g) return FALSE;

	/* At this point, we have the group, and a valid coordinate. Now we must
	 * determine that this waypoint will be aligned exclusively to either the x or
	 * y axis of the last waypoint in the list. */
	UINT8     n_aligned_axes      = 0;
	bool      reversing_direction = FALSE;
	WAYPOINT* wp                  = g->pWaypoints;
	if (!wp)
	{
		if (GroupReversingDirectionsBetweenSectors(g, x, y, TRUE))
		{
			if (g->fPlayer)
			{ /* Because we reversed, we must add the new current sector back at the
				 * head of everyone's mercpath */
				AddSectorToFrontOfMercPathForAllSoldiersInGroup(g, g->ubSectorX, g->ubSectorY);
			}

			/* Very special case that requiring specific coding. Check out the
			 * comments at the above function for more information. */
			reversing_direction = TRUE;
			// ARM:  Kris - new rulez.  Must still fall through and add a waypoint anyway!!!
		}
		else
		{ // No waypoints, so compare against the current location.
			if (g->ubSectorX == x) ++n_aligned_axes;
			if (g->ubSectorY == y) ++n_aligned_axes;
		}
	}
	else
	{	//we do have a waypoint list, so go to the last entry
		while (wp->next)
		{
			wp = wp->next;
		}
		// Now, we are pointing to the last waypoint in the list
		if (wp->x == x) ++n_aligned_axes;
		if (wp->y == y) ++n_aligned_axes;
	}

	if (!reversing_direction)
	{
		if (n_aligned_axes == 0)
		{
			AssertMsg(FALSE, String("Invalid DIAGONAL waypoint being added for groupID %d. AM-0", g->ubGroupID));
			return FALSE;
		}

		if (n_aligned_axes >= 2)
		{
			AssertMsg(FALSE, String("Invalid IDENTICAL waypoint being added for groupID %d. AM-0", g->ubGroupID));
			return FALSE;
		}

		// Has to be different in exactly 1 axis to be a valid new waypoint
		Assert(n_aligned_axes == 1);
	}

	WAYPOINT* const new_wp = new WAYPOINT{};
	new_wp->x    = x;
	new_wp->y    = y;
	new_wp->next = 0;

	if (wp)
	{ // Add the waypoint to the end of the list
		wp->next = new_wp;
	}
	else
	{ // We are adding the first waypoint.
		g->pWaypoints = new_wp;

		/* Important: The first waypoint added actually initiates the group's
		 * movement to the next sector. */
		/* Don't do this if we have reversed directions! In that case, the required
		 * work has already been done back there */
		if (!reversing_direction)
		{ /* We need to calculate the next sector the group is moving to and post an
			 * event for it. */
			InitiateGroupMovementToNextSector(g);
		}
	}

	if (g->fPlayer)
	{ // Also, nuke any previous "tactical traversal" information.
		CFOR_EACH_PLAYER_IN_GROUP(curr, g)
		{
			curr->pSoldier->ubStrategicInsertionCode = 0;
		}
	}

	return TRUE;
}