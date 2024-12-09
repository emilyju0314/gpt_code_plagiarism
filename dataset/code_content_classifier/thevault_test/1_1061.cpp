bool CSpawnPointGenerator::CheckZ( SpawnGridLoc *refLoc )
{
	//return true;
	trace_t tr;
	Vector refOrigin = refLoc->vecOrigin;

	// check for a point below within z tolerance
	UTIL_TraceHull(refOrigin, refOrigin + Vector(0,0,ZTOL), TRACE_HULL_MIN, TRACE_HULL_MAX, MASK_PLAYERSOLID, NULL, COLLISION_GROUP_NONE, &tr);
	
	refOrigin = tr.endpos;

	// if we didn't hit anything or we hit water when we're not supposed to set the point to blocked
	if ( ( tr.fraction == 1.0f ) || (!m_bWaterOk && (enginetrace->GetPointContents( tr.endpos ) & (CONTENTS_WATER|CONTENTS_SLIME))) )
		return false;
	else
		// if the down trace worked out trace up about the size of a spawnpoint
		UTIL_TraceHull(refOrigin, refOrigin + Vector(0,0,72), Vector(-16,-16,0), Vector(16,16,2), MASK_PLAYERSOLID, NULL, COLLISION_GROUP_NONE, &tr);

	// this time we prefer not to hit anything
	if ( tr.fraction == 1.0f )
	{
		refLoc->vecOrigin = refOrigin;
		return true;
	}

	return false;
}