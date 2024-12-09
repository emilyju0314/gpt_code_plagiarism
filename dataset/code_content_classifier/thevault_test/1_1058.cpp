void CSpawnPointGenerator::InitSpawnGrid()
{		
	Vector vecForward, vecRight, vecUp;
	AngleVectors( m_angles, &vecForward, &vecRight, &vecUp );

	vecForward.z = 0.0f;
	vecRight.z = 0.0f;
	VectorNormalize(vecForward);
	VectorNormalize(vecRight);

	// straighten it out to closest NOR/EST/SOU/WES before we make a grid
	if (fabs(vecForward.x) > fabs(vecRight.x))
	{
		if (vecForward.x > 0)
		{
			vecForward.x = 1;
			vecRight.y = -1;
		}
		else
		{
			vecForward.x = -1;
			vecRight.y = 1;	
		}
		vecForward.y = 0;
		vecRight.x = 0;
	}
	else
	{
		if (vecRight.x > 0)
		{
			vecForward.y = 1;
			vecRight.x = 1;
		}
		else
		{
			vecForward.y = -1;
			vecRight.x = -1;	
		}
		vecForward.x = 0;
		vecRight.y = 0;
	}

	vecForward *= DIST_TO_NEXT;
	vecRight *= DIST_TO_NEXT;
	
	Vector vecLeft = -vecRight;
	Vector vecBack = -vecForward;

	// populate spawngrid
	// start from lowest index (frontmost/rightmost location)
	Vector vecStart;
	SpawnGridLoc *pLoc;

	// use coordinates to measure each point's origin relative to distance from center
	for (int i = iMinX; i <= iMaxX; i++)
	{
		vecStart = m_vecCenter + vecLeft * i;
		for (int k = iMinY; k <= iMaxY; k++)
		{
			pLoc = GridLoc(i,k);
			pLoc->vecOrigin = (vecStart + vecBack * k);
			pLoc->xIndex = i;
			pLoc->yIndex = k;
			pLoc->iStatus = UNCHECKED;
		}
	}
}