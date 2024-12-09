static void SelectFirstDisplayedMerc(void)
{
	// set current soldier
	if (fCurrentTeamMode)
	{
		CFOR_EACH_PERSONNEL(s)
		{
			iCurrentPersonSelectedId = 0;
			return;
		}
		iCurrentPersonSelectedId = -1;
	}
	else
	{
		iCurrentPersonSelectedId = GetNumberOfPastMercsOnPlayersTeam() > 0 ? 0 : -1;
	}
}