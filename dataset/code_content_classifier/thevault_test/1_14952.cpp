void AddPossiblePendingEnemiesToBattle()
{
	if (!gfPendingEnemies)
	{ /* Optimization: No point in checking if we know that there aren't any more
		 * enemies that can be added to this battle. This changes whenever a new
		 * enemy group arrives at the scene. */
		return;
	}

	UINT8 n_slots = NumFreeEnemySlots();
	CFOR_EACH_ENEMY_GROUP(i)
	{
		if (n_slots == 0) break;

		GROUP const& g = *i;
		if (g.fVehicle)                   continue;
		if (g.ubSectorX != gWorldSectorX) continue;
		if (g.ubSectorY != gWorldSectorY) continue;
		if (gbWorldSectorZ != 0)          continue;
		// This enemy group is currently in the sector.
		ENEMYGROUP& eg          = *g.pEnemyGroup;
		UINT8       n_elites    = 0;
		UINT8       n_troops    = 0;
		UINT8       n_admins    = 0;
		UINT8       n_available = g.ubGroupSize - eg.ubElitesInBattle - eg.ubTroopsInBattle - eg.ubAdminsInBattle;
		while (n_available != 0 && n_slots != 0)
		{ // This group has enemies waiting for a chance to enter the battle.
			if (eg.ubTroopsInBattle < eg.ubNumTroops)
			{ // Add a regular troop.
				++eg.ubTroopsInBattle;
				++n_troops;
			}
			else if (eg.ubElitesInBattle < eg.ubNumElites)
			{ // Add an elite troop.
				++eg.ubElitesInBattle;
				++n_elites;
			}
			else if (eg.ubAdminsInBattle < eg.ubNumAdmins)
			{ // Add an admin troop.
				++eg.ubAdminsInBattle;
				++n_admins;
			}
			else
			{
				throw std::logic_error("AddPossiblePendingEnemiesToBattle(): Logic Error");
			}
			--n_available;
			--n_slots;
		}

		if (n_admins != 0 || n_troops != 0 || n_elites != 0)
		{ /* This group has contributed forces, then add them now, because different
			 * groups appear on different sides of the map. */
			UINT8 strategic_insertion_code = 0;
			//First, determine which entrypoint to use, based on the travel direction of the group.
			if (g.ubPrevX != 0 && g.ubPrevY != 0)
			{
				strategic_insertion_code =
					g.ubSectorX < g.ubPrevX ? INSERTION_CODE_EAST  :
					g.ubSectorX > g.ubPrevX ? INSERTION_CODE_WEST  :
					g.ubSectorY < g.ubPrevY ? INSERTION_CODE_SOUTH :
					g.ubSectorY > g.ubPrevY ? INSERTION_CODE_NORTH :
					0; // XXX exception?
			}
			else if (g.ubNextX != 0 && g.ubNextY != 0)
			{
				strategic_insertion_code =
					g.ubSectorX < g.ubNextX ? INSERTION_CODE_EAST  :
					g.ubSectorX > g.ubNextX ? INSERTION_CODE_WEST  :
					g.ubSectorY < g.ubNextY ? INSERTION_CODE_SOUTH :
					g.ubSectorY > g.ubNextY ? INSERTION_CODE_NORTH :
					0; // XXX exception?
			} // XXX else exception?
			/* Add the number of each type of troop and place them in the appropriate
			 * positions */
			AddEnemiesToBattle(g, strategic_insertion_code, n_admins, n_troops, n_elites);
		}
	}

	if (n_slots != 0)
	{ /* After going through the process, we have finished with some free slots
		 * and no more enemies to add. So, we can turn off the flag, as this check
		 * is no longer needed. */
		gfPendingEnemies = FALSE;
	}
}