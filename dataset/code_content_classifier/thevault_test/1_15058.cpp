FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (MercIsInsurable(s))
		{
			g_insurance_merc_array[g_n_insurable_mercs++] = s;
		}
	}