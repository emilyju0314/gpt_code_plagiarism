static void ProfileStatChange(MERCPROFILESTRUCT& p, StatKind const ubStat, UINT16 const usNumChances, StatChangeCause const ubReason)
{
	// dead guys don't do nuthin' !
	if (p.bMercStatus == MERC_IS_DEAD)
		return;

	if (p.bLife < OKLIFE)
		return;

	ProcessStatChange(p, ubStat, usNumChances, ubReason);

	// Update stats....right away... ATE
	ProfileUpdateStats(p);
}