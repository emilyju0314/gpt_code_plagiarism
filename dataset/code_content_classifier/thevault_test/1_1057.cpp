CSpawnPointGenerator::CSpawnPointGenerator( CBaseEntity *pRefEnt, int team, int numSpawns)
{
	m_vecCenter = pRefEnt->GetAbsOrigin();
	m_angles = pRefEnt->GetAbsAngles();
	m_pszPointName = (team == SDK_TEAM_BLUE ? "info_player_blue" : "info_player_red");
	m_iSpawnsDesired = numSpawns;
	m_iSpawnsCreated = 0;
	
	// make our trace hull very short so we can account for small z changes in geometry
	TRACE_HULL_MIN = VEC_DUCK_HULL_MIN;
	TRACE_HULL_MAX = VEC_DUCK_HULL_MAX;

	// trace down to see if our initial point is over water, if so we allow other points to be created over water
	trace_t tr;
	UTIL_TraceLine(m_vecCenter, m_vecCenter + Vector(0,0,-MAX_TRACE_LENGTH), (MASK_PLAYERSOLID|MASK_WATER), NULL, &tr);
	if ( enginetrace->GetPointContents( tr.endpos ) & (CONTENTS_WATER|CONTENTS_SLIME) )
		m_bWaterOk = true;
	else
		m_bWaterOk = false;

	// offset from ground so minor terrain changes don't block trace
	m_vecCenter.z = tr.endpos.z + 48.0f;

	Vector size = m_vecCenter - tr.endpos;

	iCurMinX = -EXTEND_FROM_CENTER;
	iCurMinY = -EXTEND_FROM_CENTER;

	InitSpawnGrid();
	PopulateSpawnGrid();
}