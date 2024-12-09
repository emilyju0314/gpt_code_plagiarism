static void AddTextToTownBox(PopUpBox* const box)
{
	ST::string wString;
	INT16 sMineSector = 0;

	UINT8 const sector   = SECTOR(bCurrentTownMineSectorX, bCurrentTownMineSectorY);
	UINT8 const ubTownId = GetTownIdForSector(sector);
	Assert((ubTownId >= FIRST_TOWN) && (ubTownId < NUM_TOWNS));

	ST::string title = GetSectorLandTypeString(sector, 0, true);

	AddMonoString(box, title);
	// blank line
	AddMonoString(box, ST::null);

	AddSectorToBox(box);

	// town size
	wString = ST::format("{}:", pwTownInfoStrings[ 0 ]);
	AddMonoString(box, wString);
	wString = ST::format("{}",  GetTownSectorSize( ubTownId ));
	AddSecondColumnMonoString(box, wString);

	// main facilities
	wString = ST::format("{}:", pwTownInfoStrings[4]);
	AddMonoString(box, wString);
	wString = GetSectorFacilitiesFlags(bCurrentTownMineSectorX, bCurrentTownMineSectorY);
	AddSecondColumnMonoString(box, wString);

	// the concept of control is only meaningful in sectors where militia can be trained
	if ( MilitiaTrainingAllowedInSector( bCurrentTownMineSectorX, bCurrentTownMineSectorY, 0 ) )
	{
		// town control
		wString = ST::format("{}:", pwTownInfoStrings[1]);
		AddMonoString(box, wString);
		wString = ST::format("{}%", GetTownSectorsUnderControl(ubTownId) * 100 / GetTownSectorSize(ubTownId));
		AddSecondColumnMonoString(box, wString);
	}

	// the concept of town loyalty is only meaningful in towns where loyalty is tracked
	if( gTownLoyalty[ ubTownId ].fStarted && gfTownUsesLoyalty[ ubTownId ])
	{
		// town loyalty
		wString = ST::format("{}:", pwTownInfoStrings[3]);
		AddMonoString(box, wString);
		wString = ST::format("{}%", gTownLoyalty[ubTownId].ubRating);
		AddSecondColumnMonoString(box, wString);
	}

	// if the town has a mine
	sMineSector = GetMineSectorForTown( ubTownId );
	if( sMineSector != -1 )
	{
		// Associated Mine: Sector
		wString = ST::format("{}:",  pwTownInfoStrings[2]);
		AddMonoString(box, wString);
		wString = GetShortSectorString(( INT16 )( sMineSector % MAP_WORLD_X ), ( INT16 )( sMineSector / MAP_WORLD_X ));
		AddSecondColumnMonoString(box, wString);
	}
}