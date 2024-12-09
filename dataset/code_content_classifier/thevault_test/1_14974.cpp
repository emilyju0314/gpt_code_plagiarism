CFOR_EACH_IN_TEAM(s, bTeam)
	{
		// Add guy if he's a candidate...
		if (pSoldier->bInSector && s->bLife >= OKLIFE && s->bBreath >= OKBREATH && s->bOppCnt > 0 && s->ubProfile != NO_PROFILE)
		{
			if (bTeam == CIV_TEAM && pSoldier->ubCivilianGroup != NON_CIV_GROUP && s->ubCivilianGroup != pSoldier->ubCivilianGroup)
			{
				continue;
			}

			if (!(gMercProfiles[s->ubProfile].ubMiscFlags & PROFILE_MISC_FLAG_SAID_HOSTILE_QUOTE))
			{
				ubMercsAvailable[ubNumMercsAvailable] = s->ubProfile;
				ubNumMercsAvailable++;
			}
		}
	}