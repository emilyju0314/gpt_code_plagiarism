UINT8 PlayerMercsInSector(UINT8 const x, UINT8 const y, UINT8 const z)
{
	UINT8 n_mercs = 0;
	CFOR_EACH_PLAYER_GROUP(g)
	{
		if (g->fBetweenSectors) continue;
		if (g->ubSectorX != x || g->ubSectorY != y || g->ubSectorZ != z) continue;
		/* We have a group, make sure that it isn't a group containing only dead
		 * members. */
		CFOR_EACH_PLAYER_IN_GROUP(p, g)
		{
			SOLDIERTYPE const* const s = p->pSoldier;
			if (s->bLife == 0)                      continue;
			// Robots count as mercs here, because they can fight, but vehicles don't
			if (s->uiStatusFlags & SOLDIER_VEHICLE) continue;
			n_mercs++;
		}
	}
	return n_mercs;
}