void HandleUnhiredMercImprovement(MERCPROFILESTRUCT& p)
{
	UINT8 ubNumStats;
	UINT16 usNumChances;

	ubNumStats = LAST_CHANGEABLE_STAT - FIRST_CHANGEABLE_STAT + 1;

	// if he's working on another job
	if (p.bMercStatus == MERC_WORKING_ELSEWHERE)
	{
		// if he did't do anything interesting today
		if (Random(100) < 20)
		{
			// no chance to change today
			return;
		}

		// it's real on the job experience, counts towards experience

		// all stats (including experience itself) get an equal chance to improve
		// 80 wisdom gives 8 rolls per stat per day, 10 stats, avg success rate 40% = 32pts per day,
		// so about 10 working days to hit lvl 2.  This seems high, but mercs don't actually "work" that often,
		// and it's twice as long to hit level 3.  If we go lower, attribs & skills will barely move.
		usNumChances = p.bWisdom / 10;
		for (StatKind ubStat = FIRST_CHANGEABLE_STAT; ubStat <= LAST_CHANGEABLE_STAT; ++ubStat)
		{
			ProfileStatChange(p, ubStat, usNumChances, FROM_SUCCESS);
		}
	}
	else
	{
		// if the merc just takes it easy (high level or stupid mercs are more likely to)
		if ((INT8)Random(10) < p.bExpLevel || (INT8)Random(100) > p.bWisdom)
		{
			// no chance to change today
			return;
		}

		// it's just practise/training back home
		StatKind ubStat;
		do
		{
			// pick ONE stat at random to focus on (it may be beyond training cap, but so what,
			// too hard to weed those out)
			ubStat = static_cast<StatKind>(FIRST_CHANGEABLE_STAT + Random(ubNumStats));
			// except experience - can't practise that!
		} while (ubStat == EXPERAMT);

		// try to improve that one stat
		ProfileStatChange(p, ubStat, (UINT16)(p.bWisdom / 2), FROM_TRAINING);
	}

	ProfileUpdateStats(p);
}