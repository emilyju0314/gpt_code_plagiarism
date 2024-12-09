static void DisplayStateOfPastTeamMembers(void)
{
	INT16 sX, sY;
	ST::string sString;

	// dead
	MPrint(PERS_CURR_TEAM_COST_X, PERS_CURR_TEAM_COST_Y, pPersonelTeamStrings[5]);
	sString = ST::format("{}", GetNumberOfDeadOnPastTeam());
	FindFontRightCoordinates(PERS_CURR_TEAM_COST_X, 0, PERS_DEPART_TEAM_WIDTH, 0, sString, PERS_FONT, &sX, &sY);
	MPrint(sX, PERS_CURR_TEAM_COST_Y, sString);

	// fired
	MPrint(PERS_CURR_TEAM_COST_X, PERS_CURR_TEAM_HIGHEST_Y, pPersonelTeamStrings[6]);
	sString = ST::format("{}", GetNumberOfLeftOnPastTeam());
	FindFontRightCoordinates(PERS_CURR_TEAM_COST_X, 0, PERS_DEPART_TEAM_WIDTH, 0, sString, PERS_FONT, &sX, &sY);
	MPrint(sX, PERS_CURR_TEAM_HIGHEST_Y, sString);

	// other
	MPrint(PERS_CURR_TEAM_COST_X, PERS_CURR_TEAM_LOWEST_Y, pPersonelTeamStrings[7]);
	sString = ST::format("{}", GetNumberOfOtherOnPastTeam());
	FindFontRightCoordinates(PERS_CURR_TEAM_COST_X, 0, PERS_DEPART_TEAM_WIDTH, 0, sString, PERS_FONT, &sX, &sY);
	MPrint(sX, PERS_CURR_TEAM_LOWEST_Y, sString);
}