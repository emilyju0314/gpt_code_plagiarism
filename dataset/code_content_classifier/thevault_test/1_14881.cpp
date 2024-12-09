static void AwardExperienceForTravelling(GROUP& g)
{
	UINT32 const traverse_time = g.uiTraverseTime;
	CFOR_EACH_PLAYER_IN_GROUP(i, &g)
	{
		if (!i->pSoldier)    continue;
		SOLDIERTYPE& s = *i->pSoldier;
		if (IsMechanical(s)) continue;
		if (AM_AN_EPC(&s))   continue;

		if (s.bLifeMax < 100)
		{
			/* Amount was originally based on getting 100 - bLifeMax points for 12
			 * hours of travel (720), but changed to flat rate since StatChange makes
			 * roll vs 100-lifemax as well */
			UINT32 const points = traverse_time / (450 / (100 - s.bLifeMax));
			if (points > 0) StatChange(s, HEALTHAMT, (UINT8)points, FROM_SUCCESS);
		}

		if (s.bStrength < 100)
		{
			UINT32 const carried_percent = CalculateCarriedWeight(&s);
			if (carried_percent > 50)
			{
				UINT32 const points = traverse_time / (450 / (100 - s.bStrength));
				StatChange(s, STRAMT, points * (carried_percent - 50) / 100, FROM_SUCCESS);
			}
		}
	}
}