FOR_EACH_MERC(i)
	{
		SOLDIERTYPE* const tgt = *i;
		if (tgt->bTeam != pSoldier->bTeam &&
			PythSpacesAway(pSoldier->sGridNo, tgt->sGridNo) < XRAY_RANGE)
		{
			tgt->ubMiscSoldierFlags |= SOLDIER_MISC_XRAYED;
			tgt->xrayed_by           = pSoldier;
		}
	}