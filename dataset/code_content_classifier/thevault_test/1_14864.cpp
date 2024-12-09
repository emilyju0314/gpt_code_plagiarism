void StatChange(SOLDIERTYPE& s, StatKind const stat, UINT16 const n_chances, StatChangeCause const reason)
{
	Assert(s.bActive);

	// Ignore non-player soldiers
	if (!IsOnOurTeam(s)) return;

	// Ignore anything without a profile
	if (s.ubProfile == NO_PROFILE) return;

	// Ignore vehicles and robots
	if (s.uiStatusFlags & SOLDIER_VEHICLE) return;
	if (s.uiStatusFlags & SOLDIER_ROBOT)   return;

	if (s.bAssignment == ASSIGNMENT_POW)
	{
		SLOGE("StatChange: %s improving stats while POW! stat %d", s.name.c_str(), stat);
		return;
	}

	// No points earned while somebody is unconscious (for assist XPs, and such)
	if (s.bLife < CONSCIOUSNESS) return;

	MERCPROFILESTRUCT& p = GetProfile(s.ubProfile);
	ProcessStatChange(p, stat, n_chances, reason);
	// ATE: Update stats right away
	ProcessUpdateStats(p, &s);
}