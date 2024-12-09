static BOOLEAN PossibleToCoordinateSimultaneousGroupArrivals(GROUP* const first_group)
{
	// If the user has already been asked, then don't ask the question again!
	if (first_group->uiFlags & (GROUPFLAG_SIMULTANEOUSARRIVAL_APPROVED | GROUPFLAG_SIMULTANEOUSARRIVAL_CHECKED)) return FALSE;
	if (IsGroupTheHelicopterGroup(*first_group)) return FALSE;

	/* Count the number of groups that are scheduled to arrive in the same sector
	 * and are currently adjacent to the sector in question. */
	UINT8 n_nearby_groups = 0;
	FOR_EACH_PLAYER_GROUP(i)
	{
		GROUP& g = *i;
		if (&g == first_group)                                 continue;
		if (!g.fBetweenSectors)                                continue;
		if (g.ubNextX != first_group->ubSectorX)               continue;
		if (g.ubNextY != first_group->ubSectorY)               continue;
		if (g.uiFlags & GROUPFLAG_SIMULTANEOUSARRIVAL_CHECKED) continue;
		if (IsGroupTheHelicopterGroup(g))                      continue;
		g.uiFlags |= GROUPFLAG_SIMULTANEOUSARRIVAL_CHECKED;
		++n_nearby_groups;
	}

	if (n_nearby_groups == 0) return FALSE;

	// Postpone the battle until the user answers the dialog.
	InterruptTime();
	PauseGame();
	LockPauseState(LOCK_PAUSE_SIMULTANEOUS_ARRIVAL);
	gpPendingSimultaneousGroup = first_group;

	ST::string pStr =
		n_nearby_groups == 1 ? gpStrategicString[STR_DETECTED_SINGULAR] :
		gpStrategicString[STR_DETECTED_PLURAL];
	ST::string enemy_type =
		gubEnemyEncounterCode == ENTERING_BLOODCAT_LAIR_CODE ? gpStrategicString[STR_PB_BLOODCATS] :
		gpStrategicString[STR_PB_ENEMIES];
	/* header, sector, singular/plural str, confirmation string.
	 * Ex:  Enemies have been detected in sector J9 and another squad is about to
	 *      arrive.  Do you wish to coordinate a simultaneous arrival? */
	ST::string str = st_format_printf(pStr, enemy_type, 'A' + first_group->ubSectorY - 1, first_group->ubSectorX);
	str += ST::format(" {}", gpStrategicString[STR_COORDINATE]);
	DoMapMessageBox(MSG_BOX_BASIC_STYLE, str, guiCurrentScreen, MSG_BOX_FLAG_YESNO, PlanSimultaneousGroupArrivalCallback);
	gfWaitingForInput = TRUE;
	return TRUE;
}