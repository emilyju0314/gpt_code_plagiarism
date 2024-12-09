void CSpawnPointGenerator::PopulateSpawnGrid()
{
	// only allow us to expand in positive axes for now
	iCurMinX = 0;
	iCurMinY = 0;

	// start by filling a line back from our center point
	FillInDir(GridLoc(0,0), DIR_BACK);

	// iterate the try lists until all valid grid locations are assigned a spawn point
	ParseTryList(DIR_LEFT);

	// if we still need points, expand to the grid quadrant in the negative x axis
	SpawnGridLoc *pLoc;
	if (m_iSpawnsCreated < m_iSpawnsDesired)
	{
		iCurMinX = -EXTEND_FROM_CENTER;

		// have each of our rightmost points add themselves to the try lists
		for( int i = 0; i <= iMaxY; i++)
		{
			pLoc = GridLoc(0,i);
			if (pLoc->iStatus == OCCUPIED)
				UpdateTryLists(pLoc);
		}

		// iterate the try lists, starting with the check-right list
		ParseTryList(DIR_RIGHT);
	}

	// if we still need points then expand to the negative y axis
	if (m_iSpawnsCreated < m_iSpawnsDesired)
	{
		iCurMinY = -EXTEND_FROM_CENTER;
		for (int i = iMaxX; i >= iMinX; i--)
		{
			pLoc = GridLoc(i,0);
			if (pLoc->iStatus == OCCUPIED)
				UpdateTryLists(pLoc);
		}

		ParseTryList(DIR_FRONT);
	}
}