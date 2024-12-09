FOR_EACH_TOWN_SECTOR(i)
	{
		bTownId = i->town;

		// skip path test if distance is already known to be zero to speed this up a bit
		if (iShortestDistance[ bTownId ] > 0 )
		{
			// calculate across how many sectors the fastest travel path from event to this town sector
			iThisDistance = FindStratPath(sEventSector, SECTOR_INFO_TO_STRATEGIC_INDEX(i->sector), g, FALSE);

			if (iThisDistance < iShortestDistance[ bTownId ])
			{
				iShortestDistance[ bTownId ] = iThisDistance;
			}
		}
	}