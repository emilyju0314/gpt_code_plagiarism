FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (s != pKillerSoldier &&
			OkControllableMerc(s) &&
			!(s->uiStatusFlags & SOLDIER_GASSED) &&
			!AM_AN_EPC(s) &&
			QuoteExp_WitnessQueenBugDeath[s->ubProfile])
		{
			// Can we see location?
			const INT16 sDistVisible = DistanceVisible(s, DIRECTION_IRRELEVANT, DIRECTION_IRRELEVANT, sGridNo, bLevel);
			if (SoldierTo3DLocationLineOfSightTest(s, sGridNo, bLevel, 3, sDistVisible, TRUE))
			{
				TacticalCharacterDialogue(s, QUOTE_KILLING_QUEEN);
			}
		}
	}