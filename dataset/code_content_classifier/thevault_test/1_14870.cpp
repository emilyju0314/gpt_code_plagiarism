FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (s->bInSector &&
			IsMercOnCurrentSquad(s) &&
			s->bLife >= CONSCIOUSNESS &&
			!IsMechanical(*s))
		{
			StatChange(*s, EXPERAMT, usXPs, FROM_SUCCESS);
		}
	}