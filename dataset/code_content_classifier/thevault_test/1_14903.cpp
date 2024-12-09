static BOOLEAN TestForBloodcatAmbush(GROUP const* const pGroup)
{
	SECTORINFO *pSector;
	INT32 iHoursElapsed;
	UINT8 ubSectorID;
	UINT8 ubChance;
	INT8 bDifficultyMaxCats;
	INT8 bProgressMaxCats;
	INT8 bNumMercMaxCats;
	BOOLEAN fAlreadyAmbushed = FALSE;

	if( pGroup->ubSectorZ )
	{ //no ambushes underground (no bloodcats either)
		return FALSE;
	}

	ubSectorID = (UINT8)SECTOR( pGroup->ubSectorX, pGroup->ubSectorY );
	pSector = &SectorInfo[ ubSectorID ];

	ubChance = 5 * gGameOptions.ubDifficultyLevel;

	bool bIsLair = false, bIsArena = false;
	auto spawns = GCM->getBloodCatSpawnsOfSector( ubSectorID );
	if (spawns != NULL) {
		bIsLair = spawns->isLair;   // SEC_I16
		bIsArena = spawns->isArena; // SEC_N5
	}

	iHoursElapsed = (GetWorldTotalMin() - pSector->uiTimeCurrentSectorWasLastLoaded) / 60;
	if( bIsLair || bIsArena )
	{ //These are special maps -- we use all placements.
		if( pSector->bBloodCats == -1 )
		{
			pSector->bBloodCats = pSector->bBloodCatPlacements;
		}
		else if( pSector->bBloodCats > 0 && pSector->bBloodCats < pSector->bBloodCatPlacements )
		{ //Slowly have them recuperate if we haven't been here for a long time.  The population will
			//come back up to the maximum if left long enough.
			INT32 iBloodCatDiff;
			iBloodCatDiff = pSector->bBloodCatPlacements - pSector->bBloodCats;
			pSector->bBloodCats += (INT8)MIN( iHoursElapsed / 18, iBloodCatDiff );
		}
		//Once 0, the bloodcats will never recupe.
	}
	else if( pSector->bBloodCats == -1 )
	{ //If we haven't been ambushed by bloodcats yet...
		if( gfAutoAmbush || PreChance( ubChance ) )
		{
			//randomly choose from 5-8, 7-10, 9-12 bloodcats based on easy, normal, and hard, respectively
			bDifficultyMaxCats = (INT8)( Random( 4 ) + gGameOptions.ubDifficultyLevel*2 + 3 );

			//maximum of 3 bloodcats or 1 for every 6%, 5%, 4% progress based on easy, normal, and hard, respectively
			bProgressMaxCats = (INT8)MAX( CurrentPlayerProgressPercentage() / (7 - gGameOptions.ubDifficultyLevel), 3 );

			//make sure bloodcats don't outnumber mercs by a factor greater than 2
			bNumMercMaxCats = (INT8)(PlayerMercsInSector( pGroup->ubSectorX, pGroup->ubSectorY, pGroup->ubSectorZ ) * 2);

			//choose the lowest number of cats calculated by difficulty and progress.
			pSector->bBloodCats = (INT8)MIN( bDifficultyMaxCats, bProgressMaxCats );

			if( gGameOptions.ubDifficultyLevel != DIF_LEVEL_HARD )
			{ //if not hard difficulty, ensure cats never outnumber mercs by a factor of 2 (min 3 bloodcats)
				pSector->bBloodCats = (INT8)MIN( pSector->bBloodCats, bNumMercMaxCats );
				pSector->bBloodCats = (INT8)MAX( pSector->bBloodCats, 3 );
			}

			//ensure that there aren't more bloodcats than placements
			pSector->bBloodCats = (INT8)MIN( pSector->bBloodCats, pSector->bBloodCatPlacements );
		}
	}
	else if( !bIsLair )
	{
		if( !gfAutoAmbush && PreChance( 95 ) )
		{ //already ambushed here.  But 5% chance of getting ambushed again!
			fAlreadyAmbushed = TRUE;
		}
	}

	if( !fAlreadyAmbushed && !bIsArena && pSector->bBloodCats > 0 &&
			!pGroup->fVehicle && !NumEnemiesInSector( pGroup->ubSectorX, pGroup->ubSectorY ) )
	{
		if( !bIsLair || !gubFact[ FACT_PLAYER_KNOWS_ABOUT_BLOODCAT_LAIR ] )
		{
			gubEnemyEncounterCode = BLOODCAT_AMBUSH_CODE;
		}
		else
		{
			gubEnemyEncounterCode = ENTERING_BLOODCAT_LAIR_CODE;
		}
		return TRUE;
	}
	else
	{
		gubEnemyEncounterCode = NO_ENCOUNTER_CODE;
		return FALSE;
	}
}