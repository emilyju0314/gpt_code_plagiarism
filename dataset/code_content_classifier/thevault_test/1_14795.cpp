void LoadEnemySoldiersFromTempFile()
{
	gfRestoringEnemySoldiersFromTempFile = TRUE;

	INT16 const x = gWorldSectorX;
	INT16 const y = gWorldSectorY;
	INT8  const z = gbWorldSectorZ;

	auto mapFileName = GetMapTempFileName(SF_ENEMY_PRESERVED_TEMP_FILE_EXISTS, x, y, z);
	// STEP ONE: Set up the temp file to read from.
	AutoSGPFile f(GCM->tempFiles()->openForReading(mapFileName));

	// STEP TWO: Determine whether or not we should use this data.  Because it
	// is the demo, it is automatically used.

	INT16 saved_y;
	f->read(&saved_y, 2);
	if (y != saved_y)
	{
		throw std::runtime_error("Sector Y mismatch");
	}

	LoadSoldierInitListLinks(f);

	// STEP THREE: Read the data

	INT16 saved_x;
	f->read(&saved_x, 2);
	if (x != saved_x)
	{
		throw std::runtime_error("Sector X mismatch");
	}

	INT32 saved_slots;
	f->read(&saved_slots, 4);
	INT32 const slots = saved_slots;

	UINT32 timestamp;
	f->read(&timestamp, 4);

	INT8 saved_z;
	f->read(&saved_z, 1);
	if (z != saved_z)
	{
		throw std::runtime_error("Sector Z mismatch");
	}

	if (GetWorldTotalMin() > timestamp + 300)
	{
		// The file has aged.  Use the regular method for adding soldiers.
		f.Deallocate(); // Close the file before deleting it
		RemoveTempFile(SF_ENEMY_PRESERVED_TEMP_FILE_EXISTS, x, y, z);
		gfRestoringEnemySoldiersFromTempFile = FALSE;
		return;
	}

	if (slots == 0)
	{
		// No need to restore the enemy's to the map.  This means we are restoring
		// a saved game.
		gfRestoringEnemySoldiersFromTempFile = FALSE;
		return;
	}

	if (slots < 0 || 64 <= slots)
	{
		//bad IO!
		throw std::runtime_error("Invalid slot count");
	}

	// For all the enemy (enemy/creature) and civilian slots, clear the
	// fPriorityExistance flag.  We will use these flags to determine which
	// slots have been modified as we load the data into the map pristine
	// soldier init list.
	CFOR_EACH_SOLDIERINITNODE(curr)
	{
		BASIC_SOLDIERCREATE_STRUCT* const bp = curr->pBasicPlacement;
		if (!bp->fPriorityExistance)
			continue;
		if (bp->bTeam != ENEMY_TEAM && bp->bTeam != CREATURE_TEAM && bp->bTeam != CIV_TEAM)
			continue;
		bp->fPriorityExistance = FALSE;
	}

	//get the number of enemies in this sector.
	UINT8 ubStrategicElites;
	UINT8 ubStrategicTroops;
	UINT8 ubStrategicAdmins;
	UINT8 ubStrategicCreatures;
	if (z != 0)
	{
		UNDERGROUND_SECTORINFO const* const pSector = FindUnderGroundSector(x, y, z);
		if (!pSector)
		{
			throw std::runtime_error("Missing underground sector info");
		}
		ubStrategicElites = pSector->ubNumElites;
		ubStrategicTroops = pSector->ubNumTroops;
		ubStrategicAdmins = pSector->ubNumAdmins;
		ubStrategicCreatures = pSector->ubNumCreatures;
	}
	else
	{
		SECTORINFO const* const pSector = &SectorInfo[SECTOR(x, y)];
		ubStrategicCreatures = pSector->ubNumCreatures;
		GetNumberOfEnemiesInSector(x, y, &ubStrategicAdmins, &ubStrategicTroops, &ubStrategicElites);
	}

	UINT8 ubNumElites    = 0;
	UINT8 ubNumTroops    = 0;
	UINT8 ubNumAdmins    = 0;
	UINT8 ubNumCreatures = 0;
	for (INT32 i = 0; i < slots; ++i)
	{
		SOLDIERCREATE_STRUCT tempDetailedPlacement;
		UINT16 saved_checksum;
		ExtractSoldierCreateFromFileWithChecksumAndGuess(f, &tempDetailedPlacement, &saved_checksum);
		FOR_EACH_SOLDIERINITNODE(curr)
		{
			BASIC_SOLDIERCREATE_STRUCT* const bp = curr->pBasicPlacement;
			if (bp->fPriorityExistance)
				continue;
			if (bp->bTeam != tempDetailedPlacement.bTeam)
				continue;

			SOLDIERCREATE_STRUCT* dp = curr->pDetailedPlacement;
			if (dp && dp->ubProfile != NO_PROFILE)
				continue;

			bp->fPriorityExistance = TRUE;

			if (!dp)
			{
				// Need to upgrade the placement to detailed placement
				dp = new SOLDIERCREATE_STRUCT{};
				curr->pDetailedPlacement = dp;
			}
			// Now replace the map pristine placement info with the temp map file
			// version.
			*dp = tempDetailedPlacement;

			bp->fPriorityExistance = TRUE;
			bp->bDirection         = dp->bDirection;
			bp->bOrders            = dp->bOrders;
			bp->bAttitude          = dp->bAttitude;
			bp->bBodyType          = dp->bBodyType;
			bp->fOnRoof            = dp->fOnRoof;
			bp->ubSoldierClass     = dp->ubSoldierClass;
			bp->ubCivilianGroup    = dp->ubCivilianGroup;
			bp->fHasKeys           = dp->fHasKeys;
			bp->usStartingGridNo   = dp->sInsertionGridNo;
			bp->bPatrolCnt         = dp->bPatrolCnt;
			memcpy(bp->sPatrolGrid, dp->sPatrolGrid, sizeof(INT16) * bp->bPatrolCnt);

			// Verify the checksum equation (anti-hack) -- see save
			UINT16 const checksum = CalcSoldierCreateCheckSum(dp);
			if (saved_checksum != checksum)
			{
				// Hacker has modified the stats on the enemy placements.
				throw std::runtime_error("Invalid checksum for placement");
			}

			if (bp->bTeam != CIV_TEAM)
			{
				switch (bp->ubSoldierClass)
				{
					// Add preserved placements as long as they don't exceed the actual
					// population.
					case SOLDIER_CLASS_ELITE:
						if (++ubNumElites >= ubStrategicElites)
							goto no_add;
						break;
					case SOLDIER_CLASS_ARMY:
						if (++ubNumTroops >= ubStrategicTroops)
							goto no_add;
						break;
					case SOLDIER_CLASS_ADMINISTRATOR:
						if (++ubNumAdmins >= ubStrategicAdmins)
							goto no_add;
						break;
					case SOLDIER_CLASS_CREATURE:
						if (++ubNumCreatures >= ubStrategicCreatures)
							goto no_add;
						break;
					default:
						goto no_add;
				}
			}
			AddPlacementToWorld(curr);
no_add:
			break;
		}
	}

	UINT8 saved_sector_id;
	f->read(&saved_sector_id, 1);
	if (saved_sector_id != SECTOR(x, y))
	{
		throw std::runtime_error("Sector ID mismatch");
	}

	// Now add any extra enemies that have arrived since the temp file was made.
	if (ubStrategicTroops > ubNumTroops ||
		ubStrategicElites > ubNumElites ||
		ubStrategicAdmins > ubNumAdmins)
	{
		ubStrategicTroops = ubStrategicTroops > ubNumTroops ? ubStrategicTroops - ubNumTroops : 0;
		ubStrategicElites = ubStrategicElites > ubNumElites ? ubStrategicElites - ubNumElites : 0;
		ubStrategicAdmins = ubStrategicAdmins > ubNumAdmins ? ubStrategicAdmins - ubNumAdmins : 0;
		AddSoldierInitListEnemyDefenceSoldiers(ubStrategicAdmins, ubStrategicTroops, ubStrategicElites);
	}
}