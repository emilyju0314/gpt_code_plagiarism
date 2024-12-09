UINT8 CurrentPlayerProgressPercentage(void)
{
	UINT32 uiCurrentIncome;
	UINT32 uiPossibleIncome;
	UINT8 ubCurrentProgress;
	UINT8 ubKillsPerPoint;
	UINT16 usKillsProgress;
	UINT16 usControlProgress;


	if( gfEditMode )
		return 0;

	// figure out the player's current mine income
	uiCurrentIncome = PredictIncomeFromPlayerMines();

	// figure out the player's potential mine income
	uiPossibleIncome = CalcMaxPlayerIncomeFromMines();

	// either of these indicates a critical failure of some sort
	Assert(uiPossibleIncome > 0);
	Assert(uiCurrentIncome <= uiPossibleIncome);

	// for a rough guess as to how well the player is doing,
	// we'll take the current mine income / potential mine income as a percentage

	//Kris:  Make sure you don't divide by zero!!!
	if( uiPossibleIncome > 0)
	{
		ubCurrentProgress = (UINT8) ((uiCurrentIncome * PROGRESS_PORTION_INCOME) / uiPossibleIncome);
	}
	else
	{
		ubCurrentProgress = 0;
	}

	// kills per point depends on difficulty, and should match the ratios of starting enemy populations (730/1050/1500)
	switch( gGameOptions.ubDifficultyLevel )
	{
		case DIF_LEVEL_EASY:
			ubKillsPerPoint = gamepolicy(kills_per_point_easy);
			break;
		case DIF_LEVEL_MEDIUM:
			ubKillsPerPoint = gamepolicy(kills_per_point_medium);
			break;
		case DIF_LEVEL_HARD:
			ubKillsPerPoint = gamepolicy(kills_per_point_hard);
			break;
		default:
			Assert(FALSE);
			ubKillsPerPoint = 10;
			break;
	}

	if (ubKillsPerPoint > 0)
	{
		usKillsProgress = gStrategicStatus.usPlayerKills / ubKillsPerPoint;
		if (usKillsProgress > PROGRESS_PORTION_KILLS)
		{
			usKillsProgress = PROGRESS_PORTION_KILLS;
		}
	}
	else
	{
		usKillsProgress = PROGRESS_PORTION_KILLS;
	}

	// add kills progress to income progress
	ubCurrentProgress += usKillsProgress;


	// 19 sectors in mining towns + 3 wilderness SAMs each count double.  Balime & Meduna are extra and not required
	usControlProgress = CalcImportantSectorControl();
	if (usControlProgress > PROGRESS_PORTION_CONTROL)
	{
		usControlProgress = PROGRESS_PORTION_CONTROL;
	}

	// add control progress
	ubCurrentProgress += usControlProgress;

	return(ubCurrentProgress);
}