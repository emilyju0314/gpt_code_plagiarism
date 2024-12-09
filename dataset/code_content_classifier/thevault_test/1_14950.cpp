FOR_EACH_ENEMY_GROUP(g)
		{
			if (g == bg)                               continue;
			if (g->fVehicle)                           continue;
			if (g->ubSectorX != bg->ubSectorX)         continue;
			if (g->ubSectorY != bg->ubSectorY)         continue;
			if (g->pEnemyGroup->ubAdminsInBattle != 0) continue;
			if (g->pEnemyGroup->ubTroopsInBattle != 0) continue;
			if (g->pEnemyGroup->ubElitesInBattle != 0) continue;
			HandleArrivalOfReinforcements(g);
		}