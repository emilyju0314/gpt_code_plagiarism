BOOLEAN IsMercOnTeam(UINT8 ubMercID)
{
	const SOLDIERTYPE* const s = FindSoldierByProfileIDOnPlayerTeam(ubMercID);
	return s != NULL;
}