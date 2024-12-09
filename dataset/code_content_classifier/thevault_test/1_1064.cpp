CSpawnPointGenerator::SpawnGridLoc* CSpawnPointGenerator::CheckStatusInDir( SpawnGridLoc *pLoc, int dir )
{
	int x = pLoc->xIndex;
	int y = pLoc->yIndex;
	SpawnGridLoc *refLoc;

	switch(dir)
	{
	case DIR_LEFT:
		refLoc = GridLoc(x+1,y);
		break;
	case DIR_RIGHT:
		refLoc = GridLoc(x-1,y);
		break;
	case DIR_FRONT:
		refLoc = GridLoc(x,y-1);
		break;
	default:
		refLoc = GridLoc(x,y+1);
		break;
	}

	// if the point hasn't been checked trace in the given direction
	if (refLoc->iStatus == UNCHECKED)
		StepThroughDir(pLoc, dir);
	return refLoc;
}