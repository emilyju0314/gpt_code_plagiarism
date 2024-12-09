INT32 GetSectorMvtTimeForGroup(UINT8 const ubSector, UINT8 const direction, GROUP const* const g)
{
	/* Determine the group's method(s) of transportation.  If more than one, we
	 * will always use the highest time. */
	UINT8 const transport_mask     = g->ubTransportationMask;
	UINT8 const traverse_type      = SectorInfo[ubSector].ubTraversability[direction];
	INT32       best_traverse_time = 1000000;

	if (traverse_type == EDGEOFWORLD) return TRAVERSE_TIME_IMPOSSIBLE;

	/* ARM: Made air-only travel take its normal time per sector even through
	 * towns.  Because Skyrider charges by the sector, not by flying time, it's
	 * annoying when his default route detours through a town to save time, but
	 * costs extra money. This isn't exactly unrealistic, since the chopper
	 * shouldn't be faster flying over a town anyway. Not that other kinds of
	 * travel should be either - but the towns represents a kind of warping of our
	 * space-time scale as it is. */
	if (traverse_type == TOWN && transport_mask != AIR)
		return 5; // Very fast, and vehicle types don't matter.

	if (transport_mask & FOOT)
	{
		UINT8 traverse_mod;
		switch (traverse_type)
		{
			case ROAD:     traverse_mod = 100; break;
			case PLAINS:   traverse_mod =  85; break;
			case SAND:     traverse_mod =  50; break;
			case SPARSE:   traverse_mod =  70; break;
			case DENSE:    traverse_mod =  60; break;
			case SWAMP:    traverse_mod =  35; break;
			case WATER:    traverse_mod =  25; break;
			case HILLS:    traverse_mod =  50; break;
			case NS_RIVER: traverse_mod =  25; break;
			case EW_RIVER: traverse_mod =  25; break;
			default:       return TRAVERSE_TIME_IMPOSSIBLE;
		}
		INT32 const traverse_time = FOOT_TRAVEL_TIME * 100 / traverse_mod;
		if (best_traverse_time > traverse_time)
			best_traverse_time = traverse_time;

		if (g->fPlayer)
		{
			INT32 highest_encumbrance = 100;
			CFOR_EACH_PLAYER_IN_GROUP(curr, g)
			{
				SOLDIERTYPE const* const s = curr->pSoldier;
				if (s->bAssignment == VEHICLE) continue;
				/* Soldier is on foot and travelling.  Factor encumbrance into movement
				 * rate. */
				INT32 const encumbrance = CalculateCarriedWeight(s);
				if (highest_encumbrance < encumbrance)
				{
					highest_encumbrance = encumbrance;
				}
			}
			best_traverse_time = best_traverse_time * highest_encumbrance / 100;
		}
	}

	if (transport_mask & CAR)
	{
		UINT8 traverse_mod;
		switch (traverse_type)
		{
			case ROAD: traverse_mod = 100; break;
			default:   return TRAVERSE_TIME_IMPOSSIBLE;
		}
		INT32 const traverse_time = CAR_TRAVEL_TIME * 100 / traverse_mod;
		if (best_traverse_time > traverse_time)
			best_traverse_time = traverse_time;
	}

	if (transport_mask & TRUCK)
	{
		UINT8 traverse_mod;
		switch (traverse_type)
		{
			case ROAD:   traverse_mod = 100; break;
			case PLAINS: traverse_mod =  75; break;
			case SPARSE: traverse_mod =  60; break;
			case HILLS:  traverse_mod =  50; break;
			default:     return TRAVERSE_TIME_IMPOSSIBLE;
		}
		INT32 const traverse_time = TRUCK_TRAVEL_TIME * 100 / traverse_mod;
		if (best_traverse_time > traverse_time)
			best_traverse_time = traverse_time;
	}

	if (transport_mask & TRACKED)
	{
		UINT8 traverse_mod;
		switch (traverse_type)
		{
			case ROAD:     traverse_mod = 100; break;
			case PLAINS:   traverse_mod = 100; break;
			case SAND:     traverse_mod =  70; break;
			case SPARSE:   traverse_mod =  60; break;
			case HILLS:    traverse_mod =  60; break;
			case NS_RIVER: traverse_mod =  20; break;
			case EW_RIVER: traverse_mod =  20; break;
			case WATER:    traverse_mod =  10; break;
			default:       return TRAVERSE_TIME_IMPOSSIBLE;
		}
		INT32 const traverse_time = TRACKED_TRAVEL_TIME * 100 / traverse_mod;
		if (best_traverse_time > traverse_time)
			best_traverse_time = traverse_time;
	}

	if (transport_mask & AIR)
	{
		INT32 const traverse_time = AIR_TRAVEL_TIME;
		if (best_traverse_time > traverse_time)
			best_traverse_time = traverse_time;
	}

	return best_traverse_time;
}