CFOR_EACH_IN_TEAM(s, CIV_TEAM)
	{
		if (s->bInSector &&
			s->bLife >= OKLIFE &&
			!(s->uiStatusFlags & SOLDIER_GASSED) &&
			s->ubBodyType == CROW)
		{
			bNumCrows++;
		}
	}