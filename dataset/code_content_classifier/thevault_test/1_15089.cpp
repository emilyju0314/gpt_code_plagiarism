static INT32 GetAvailableWorkForceForMineForEnemy(UINT8 ubMineIndex)
{
	// look for available workforce in the town associated with the mine
	INT32 iWorkForceSize = 0;
	INT8 bTownId = 0;

	// return the loyalty of the town associated with the mine

	Assert(ubMineIndex < GCM->getMines().size());
	auto mine = GCM->getMine(ubMineIndex);

	// if mine is shut down
	if ( gMineStatus[ ubMineIndex ].fShutDown)
	{
		return ( 0 );
	}

	bTownId = mine->associatedTownId;

	UINT8 numSectors = GetTownSectorSize( bTownId );
	Assert(numSectors > 0);
	UINT8 numSectorsUnderControl = GetTownSectorsUnderControl( bTownId );
	Assert(numSectorsUnderControl <= numSectors);

	// get workforce size (is 0-100 based on REVERSE of local town's loyalty)
	iWorkForceSize = 100 - gTownLoyalty[ bTownId ].ubRating;

	// now adjust for town size.. the number of sectors you control
	iWorkForceSize = iWorkForceSize * (numSectors - numSectorsUnderControl) / numSectors;

	return ( iWorkForceSize );
}