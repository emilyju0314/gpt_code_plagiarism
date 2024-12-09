void PlayerGroupArrivedSafelyInSector(GROUP& g, BOOLEAN const fCheckForNPCs)
{
	BOOLEAN fPlayerPrompted = FALSE;

	Assert(g.fPlayer);

	// if we haven't already checked for NPCs, and the group isn't empty
	if (fCheckForNPCs && HandlePlayerGroupEnteringSectorToCheckForNPCsOfNote(g))
	{
		// wait for player to answer/confirm prompt before doing anything else
		fPlayerPrompted = TRUE;
	}

	// if we're not prompting the player
	if ( !fPlayerPrompted )
	{
		// and we're not at the end of our road
		if (!GroupAtFinalDestination(&g))
		{
			if (AnyMercInGroupCantContinueMoving(g))
			{
				// stop: clear their strategic movement (mercpaths and waypoints)
				ClearMercPathsAndWaypointsForAllInGroup(g);

				// NOTE: Of course, it would be better if they continued onwards once everyone was ready to go again, in which
				// case we'd want to preserve the plotted path, but since the player can mess with the squads, etc.
				// in the mean-time, that just seemed to risky to try to support.  They could get into a fight and be too
				// injured to move, etc.  Basically, we'd have run a complete CanCharacterMoveInStrategic(0 check on all of them.
				// It's a wish list task for AM...

				// stop time so player can react if group was already on the move and suddenly halts
				StopTimeCompression();
			}
			else
			{
				// continue onwards: rebuild way points, initiate movement
				RebuildWayPointsForGroupPath(GetGroupMercPathPtr(g), g);
			}
		}
	}
}