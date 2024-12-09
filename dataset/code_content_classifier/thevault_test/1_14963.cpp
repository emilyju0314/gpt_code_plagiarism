BOOLEAN MercThinksHisMoraleIsTooLow(SOLDIERTYPE const* const pSoldier)
{
	INT8	bRepTolerance;
	INT8	bMoraleTolerance;

	bRepTolerance = gMercProfiles[ pSoldier->ubProfile ].bReputationTolerance;

	// if he couldn't care less what it is
	if (bRepTolerance == 101)
	{
		// that obviously it CAN'T be too low...
		return(FALSE);
	}


	// morale tolerance is based directly upon reputation tolerance
	// above 50, morale is GOOD, never below tolerance then
	bMoraleTolerance = (100 - bRepTolerance) / 2;

	if (pSoldier->bMorale < bMoraleTolerance)
	{
		// too low - sorry
		return(TRUE);
	}
	else
	{
		// within tolerance
		return(FALSE);
	}
}