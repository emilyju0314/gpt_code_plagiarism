CFOR_EACH_ENEMY_GROUP(i)
	{
		GROUP const& g = *i;
		if (g.fVehicle)       continue;
		if (g.ubSectorX != x) continue;
		if (g.ubSectorY != y) continue;
		// XXX test for z missing?
		ENEMYGROUP& eg = *g.pEnemyGroup;
		eg.ubTroopsInBattle = 0;
		eg.ubElitesInBattle = 0;
		eg.ubAdminsInBattle = 0;
	}