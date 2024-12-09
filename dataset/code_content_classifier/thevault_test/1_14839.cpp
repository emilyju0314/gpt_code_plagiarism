FOR_EACH_IN_TEAM(other, OUR_TEAM)
	{
		if (other->ubWhatKindOfMercAmI != MERC_TYPE__AIM_MERC) continue;

		// hates the merc who has arrived and is going to gripe about it!
		switch (WhichHated(other->ubProfile, s.ubProfile))
		{
			case 0:  TacticalCharacterDialogue(other, QUOTE_HATED_1_ARRIVES); break;
			case 1:  TacticalCharacterDialogue(other, QUOTE_HATED_2_ARRIVES); break;
			default: break;
		}
	}