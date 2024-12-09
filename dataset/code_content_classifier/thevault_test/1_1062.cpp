void CSpawnPointGenerator::StepThroughDir( SpawnGridLoc *refLoc, int dir )
{
	int x = refLoc->xIndex;
	int y = refLoc->yIndex;

	// get max boundaries for the given direction
	int xmod = x;
	int ymod = y;
	BoundsForDir(dir, &xmod, &ymod);

	trace_t tr;
	int iClearPoints;

	// just a multiplier for a cheap way to determine direction
	int inc = 1;
		
	UTIL_TraceHull(refLoc->vecOrigin, GridLoc(xmod,ymod)->vecOrigin, TRACE_HULL_MIN, TRACE_HULL_MAX, MASK_PLAYERSOLID,
		NULL, COLLISION_GROUP_NONE, &tr);

	SpawnGridLoc *pLoc;

	// if our xbound hasn't changed it means we're iterating through the y axis
	if ( xmod == x )
	{
		if ( ymod < y )
			inc = -1;

		// take the fraction of max possible points in the given direction
		iClearPoints = inc*((-y) + ymod);
		iClearPoints *= tr.fraction;
		int i;
		for (i = 1; i <= iClearPoints; i++)
		{
			pLoc = GridLoc(x,y+(inc*i));
			// CheckZ makes sure nothing fishy is going on
			if (CheckZ(pLoc))
				pLoc->iStatus = OPEN;
			else
				pLoc->iStatus = BLOCKED;
		}
		// if we stopped before hitting our bound it means an obstruction is at this index
		i *= inc;
		i += y;
		if ( (iMinY <= i) && (i <= iMaxY) )
			GridLoc(x,i)->iStatus = BLOCKED;
	}
	else
	{
		if ( xmod < x )
			inc = -1;

		// take the fraction of max possible points in the given direction
		iClearPoints = inc*((-x) + xmod);
		iClearPoints *= tr.fraction;
		int i;
		for (i = 1; i <= iClearPoints; i++)
		{
			pLoc = GridLoc(x+(inc*i),y);
			// CheckZ makes sure nothing fishy is going on
			if (CheckZ(pLoc))
				pLoc->iStatus = OPEN;
			else
				pLoc->iStatus = BLOCKED;
		}
		// if we stopped before hitting our bound it means an obstruction is at this index
		i *= inc;
		i += x;
		if ( (iMinX <= i) && (i <= iMaxX) )
			GridLoc(i,y)->iStatus = BLOCKED;
	}
}