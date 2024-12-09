FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (s->bLife >= OKLIFE && !AM_AN_EPC(s))
		{
			TacticalCharacterDialogue(s, QUOTE_END_GAME_COMMENT);
		}
	}