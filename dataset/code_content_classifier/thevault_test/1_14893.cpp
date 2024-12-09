CFOR_EACH_PLAYER_GROUP(i)
	{
		GROUP const& g = *i;
		bool  const is_heli_group = IsGroupTheHelicopterGroup(g);

		/* If this group is aboard the helicopter and we're showing the airspace
		 * layer, don't count any mercs aboard the chopper, because the chopper icon
		 * itself serves the function of showing the location/size of this group. */
		if (is_heli_group && fShowAircraftFlag) continue;

		/* If only showing retreat paths, ignore groups not in the battle sector.
		 * If NOT showing retreat paths, ignore groups not between sectors. */
		if (gfDisplayPotentialRetreatPaths ? sec_battle != sec_src : !g.fBetweenSectors) continue;

		UINT8 n_mercs = g.ubGroupSize;
		if (n_mercs == 0) // Skip empty persistent groups
		{
			Assert(g.fPersistant);
			continue;
		}

		INT16 const sec_prev = IS_VALID_SECTOR(g.ubPrevX, g.ubPrevY) ? SECTOR(g.ubPrevX,   g.ubPrevY) : -1;
		INT16 const sec_cur  = SECTOR(g.ubSectorX, g.ubSectorY);
		INT16 const sec_next = IS_VALID_SECTOR(g.ubNextX, g.ubNextY) ? SECTOR(g.ubNextX,   g.ubNextY) : -1;

		bool const may_retreat_from_battle =
			sec_battle == sec_src && sec_cur == sec_src && sec_prev == sec_dst;

		bool const retreating_from_battle =
			sec_battle == sec_dst && sec_cur == sec_dst && sec_prev == sec_src;

		if (may_retreat_from_battle || (sec_cur == sec_src && sec_next == sec_dst))
		{
			// If it's a valid vehicle, but not the helicopter (which can fly empty)
			if (g.fVehicle && !is_heli_group)
			{ // subtract 1, we don't wanna count the vehicle itself for purposes of showing a number on the map
				n_mercs--;
			}

			*n_enter += n_mercs;

			if (may_retreat_from_battle ||
					g.uiArrivalTime - GetWorldTotalMin() <= ABOUT_TO_ARRIVE_DELAY)
			{
				*about_to_arrive_enter = TRUE;
			}
		}
		else if (retreating_from_battle || (sec_cur == sec_dst && sec_next == sec_src))
		{
			// If it's a valid vehicle, but not the helicopter (which can fly empty)
			if (g.fVehicle && !is_heli_group)
			{ // subtract 1, we don't wanna count the vehicle itself for purposes of showing a number on the map
				n_mercs--;
			}

			*n_exit += n_mercs;
		}
	}