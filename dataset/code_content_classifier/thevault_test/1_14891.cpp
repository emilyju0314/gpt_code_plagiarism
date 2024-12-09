CFOR_EACH_PLAYER_IN_GROUP(p, g)
		{
			SOLDIERTYPE const* const s = p->pSoldier;
			if (s->bLife == 0)                      continue;
			// Robots count as mercs here, because they can fight, but vehicles don't
			if (s->uiStatusFlags & SOLDIER_VEHICLE) continue;
			n_mercs++;
		}