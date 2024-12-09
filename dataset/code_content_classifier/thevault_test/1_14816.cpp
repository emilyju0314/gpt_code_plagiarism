CFOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (FindObj(s, CHALICE) != ITEM_NOT_FOUND)
		{
			SetFactTrue(FACT_CHALICE_STOLEN);
		}
	}