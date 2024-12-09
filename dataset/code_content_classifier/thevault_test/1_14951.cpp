FOR_EACH_GROUP(g)
	{
		if (n_slots == 0) break;

		if (g->fVehicle)         continue;
		if (g->ubSectorX   != x) continue;
		if (g->ubSectorY   != y) continue;
		if (gbWorldSectorZ != 0) continue;

		if (!g->fPlayer)
		{ // Process enemy group in sector
			ENEMYGROUP& eg = *g->pEnemyGroup;
			if (n_slots > 0)
			{
				UINT8 n_admins = eg.ubNumAdmins - eg.ubAdminsInBattle;
				n_slots -= n_admins;
				if (n_slots < 0)
				{ // Adjust the value to zero
					n_admins        += n_slots;
					n_slots          = 0;
					gfPendingEnemies = TRUE;
				}
				eg.ubAdminsInBattle += n_admins;
				total_admins        += n_admins;
			}
			if (n_slots > 0)
			{ // Add regular army forces
				UINT8 n_troops = eg.ubNumTroops - eg.ubTroopsInBattle;
				n_slots -= n_troops;
				if (n_slots < 0)
				{ // Adjust the value to zero
					n_troops        += n_slots;
					n_slots          = 0;
					gfPendingEnemies = TRUE;
				}
				eg.ubTroopsInBattle += n_troops;
				total_troops        += n_troops;
			}
			if (n_slots > 0)
			{ // Add elite troops
				UINT8 n_elites = eg.ubNumElites - eg.ubElitesInBattle;
				n_slots -= n_elites;
				if (n_slots < 0)
				{ // Adjust the value to zero
					n_elites        += n_slots;
					n_slots          = 0;
					gfPendingEnemies = TRUE;
				}
				eg.ubElitesInBattle += n_elites;
				total_elites        += n_elites;
			}
			// NOTE: No provisions for profile troop leader or retreat groups yet
		}
		else if (!g->fBetweenSectors)
		{ /* TEMP: The player path needs to get destroyed, otherwise, it'll be
			 * impossible to move the group after the battle is resolved. */
			// XXX TODO001F This does not work, when n_slots drops to 0 before all player groups are handled.

			// No one in the group any more continue loop
			if (!g->pPlayerList) continue;

			RemoveGroupWaypoints(*g);
		}
	}