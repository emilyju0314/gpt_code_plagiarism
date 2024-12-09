FOR_EACH_STRUCTURE(pStructure, sGridNo, STRUCTURE_WALL)
	{
		// Check orientation
		if ( pStructure->ubWallOrientation == INSIDE_TOP_RIGHT ||
			pStructure->ubWallOrientation == OUTSIDE_TOP_RIGHT )
		{
			return( TRUE );
		}
	}