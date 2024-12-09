CFOR_EACH_PLAYER_IN_GROUP(p, g)
		{
			if (p->pSoldier->bLife == 0) continue;
			++n_groups;
			break;
		}