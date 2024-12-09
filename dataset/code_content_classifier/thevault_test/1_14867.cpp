void HandleUnhiredMercDeaths( INT32 iProfileID )
{
	UINT8 ubMaxDeaths;
	INT16 sChance;
	MERCPROFILESTRUCT& p = GetProfile(iProfileID);


	// if the player has never yet had the chance to hire this merc
	if (!(p.ubMiscFlags3 & PROFILE_MISC_FLAG3_PLAYER_HAD_CHANCE_TO_HIRE))
	{
		// then we're not allowed to kill him (to avoid really pissing off player by killing his very favorite merc)
		return;
	}

	// how many in total can be killed like this depends on player's difficulty setting
	switch( gGameOptions.ubDifficultyLevel )
	{
		case DIF_LEVEL_EASY:
			ubMaxDeaths = gamepolicy(unhired_merc_deaths_easy);
			break;
		case DIF_LEVEL_MEDIUM:
			ubMaxDeaths = gamepolicy(unhired_merc_deaths_medium);
			break;
		case DIF_LEVEL_HARD:
			ubMaxDeaths = gamepolicy(unhired_merc_deaths_hard);
			break;
		default:
			Assert(FALSE);
			ubMaxDeaths = 0;
			break;
	}

	// if we've already hit the limit in this game, skip these checks
	if (gStrategicStatus.ubUnhiredMercDeaths >= ubMaxDeaths)
	{
		return;
	}


	// calculate this merc's (small) chance to get killed today (out of 1000)
	sChance = 10 - p.bExpLevel;

	switch (p.bPersonalityTrait)
	{
		case FORGETFUL:
		case NERVOUS:
		case PSYCHO:
			// these guys are somewhat more likely to get killed (they have "problems")
			sChance += 2;
			break;
	}

	// stealthy guys are slightly less likely to get killed (they're careful)
	if (p.bSkillTrait  == STEALTHY)
		sChance -= 1;
	if (p.bSkillTrait2 == STEALTHY)
		sChance -= 1;


	if ((INT16) PreRandom(1000) < sChance)
	{
		// this merc gets Killed In Action!!!
		p.bMercStatus           = MERC_IS_DEAD;
		p.uiDayBecomesAvailable = 0;

		// keep count of how many there have been
		gStrategicStatus.ubUnhiredMercDeaths++;

		//send an email as long as the merc is from aim
		if (MercProfile(iProfileID).isAIMMerc())
		{
			//send an email to the player telling the player that a merc died
			AddEmailWithSpecialData(MERC_DIED_ON_OTHER_ASSIGNMENT, MERC_DIED_ON_OTHER_ASSIGNMENT_LENGTH, AIM_SITE, GetWorldTotalMin(), 0, iProfileID );
		}
	}
}