FOR_EACH_MERC(i)
	{
		SOLDIERTYPE* const tgt = *i;
		if (tgt->ubMiscSoldierFlags &  SOLDIER_MISC_XRAYED &&
				tgt->xrayed_by          == pSoldier)
		{
			tgt->ubMiscSoldierFlags &= ~SOLDIER_MISC_XRAYED;
			tgt->xrayed_by           = NULL;
		}
	}