FOR_EACH_MERC(i)
	{
		SOLDIERTYPE& s = **i;
		if (s.target == old_s) s.target = new_s;
	}