FOR_EACH_STRUCTURE(pStructure, sGridNo, STRUCTURE_WALL)
	{
		// Check orientation
		if ( pStructure->ubWallOrientation == INSIDE_TOP_LEFT ||
			pStructure->ubWallOrientation == OUTSIDE_TOP_LEFT )
		{
			return( TRUE );
		}
	}