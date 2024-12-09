FOR_EACH_IN_TEAM(s, OUR_TEAM)
		{
			if (s->bInSector && s->uiStatusFlags & SOLDIER_MULTI_SELECTED)
			{
				MakeSoldierTurn(s, pos);
			}
		}