void NewWayOfSavingEnemyAndCivliansToTempFile(INT16 const sSectorX, INT16 const sSectorY, INT8 const bSectorZ, BOOLEAN const fEnemy, BOOLEAN const fValidateOnly)
{
	//if we are saving the enemy info to the enemy temp file
	UINT8       first_team;
	UINT8       last_team;
	SectorFlags file_flag;
	if (fEnemy)
	{
		first_team = ENEMY_TEAM;
		last_team  = CREATURE_TEAM;
		file_flag  = SF_ENEMY_PRESERVED_TEMP_FILE_EXISTS;
	}
	else
	{
		// It's the civilian team
		first_team = CIV_TEAM;
		last_team  = CIV_TEAM;
		file_flag  = SF_CIV_PRESERVED_TEMP_FILE_EXISTS;
	}

	UINT8 const first = gTacticalStatus.Team[first_team].bFirstID;
	UINT8 const last  = gTacticalStatus.Team[last_team ].bLastID;

	// STEP ONE:  Prep the soldiers for saving

	// Modify the map's soldier init list to reflect the changes to the member's
	// still alive
	INT32 slots = 0;
	for (INT32 i = first; i <= last; ++i)
	{
		SOLDIERTYPE const& s = GetMan(i);

		// Make sure the person is active, alive, and is not a profiled person
		if (!s.bActive || s.bLife == 0 || s.ubProfile != NO_PROFILE)
			continue;
		// Soldier is valid, so find the matching soldier init list entry for modification.
		SOLDIERINITNODE* const curr = FindSoldierInitNodeBySoldier(s);
		if (!curr)
			continue;

		// Increment the counter, so we know how many there are.
		slots++;

		if (fValidateOnly)
			continue;
		if (gTacticalStatus.uiFlags & LOADING_SAVED_GAME)
			continue;

		SOLDIERCREATE_STRUCT* dp = curr->pDetailedPlacement;
		if (!dp)
		{
			//need to upgrade the placement to detailed placement
			dp                                        = new SOLDIERCREATE_STRUCT{};
			curr->pDetailedPlacement                  = dp;
			curr->pBasicPlacement->fDetailedPlacement = TRUE;
		}

		//Copy over the data of the soldier.
		dp->ubProfile       = NO_PROFILE;
		dp->bLife           = s.bLife;
		dp->bLifeMax        = s.bLifeMax;
		dp->bAgility        = s.bAgility;
		dp->bDexterity      = s.bDexterity;
		dp->bExpLevel       = s.bExpLevel;
		dp->bMarksmanship   = s.bMarksmanship;
		dp->bMedical        = s.bMedical;
		dp->bMechanical     = s.bMechanical;
		dp->bExplosive      = s.bExplosive;
		dp->bLeadership     = s.bLeadership;
		dp->bStrength       = s.bStrength;
		dp->bWisdom         = s.bWisdom;
		dp->bAttitude       = s.bAttitude;
		dp->bOrders         = s.bOrders;
		dp->bMorale         = s.bMorale;
		dp->bAIMorale       = s.bAIMorale;
		dp->bBodyType       = s.ubBodyType;
		dp->ubCivilianGroup = s.ubCivilianGroup;
		dp->ubScheduleID    = s.ubScheduleID;
		dp->fHasKeys        = s.bHasKeys;
		dp->sSectorX        = s.sSectorX;
		dp->sSectorY        = s.sSectorY;
		dp->bSectorZ        = s.bSectorZ;
		dp->ubSoldierClass  = s.ubSoldierClass;
		dp->bTeam           = s.bTeam;
		dp->bDirection      = s.bDirection;

		// We don't want the player to think that all the enemies start in the exact
		// position when we left the map, so randomize the start locations either
		// current position or original position.
		if (PreRandom(2))
		{
			// Use current position
			dp->fOnRoof          = s.bLevel;
			dp->sInsertionGridNo = s.sGridNo;
		}
		else
		{
			// Use original position
			dp->fOnRoof          = curr->pBasicPlacement->fOnRoof;
			dp->sInsertionGridNo = curr->pBasicPlacement->usStartingGridNo;
		}

		dp->name = s.name;

		// Copy patrol points
		dp->bPatrolCnt = s.bPatrolCnt;
		memcpy(dp->sPatrolGrid, s.usPatrolGrid, sizeof(dp->sPatrolGrid));

		// Copy colors for soldier based on the body type.
		dp->HeadPal = s.HeadPal;
		dp->VestPal = s.VestPal;
		dp->SkinPal = s.SkinPal;
		dp->PantsPal = s.PantsPal;

		// Copy soldier's inventory
		memcpy(dp->Inv, s.inv, sizeof(dp->Inv));
	}

	auto mapFileName = GetMapTempFileName(file_flag, sSectorX, sSectorY, bSectorZ);
	if (slots == 0)
	{
		// No need to save anything, so return successfully
		RemoveTempFile(file_flag, sSectorX, sSectorY, bSectorZ);
		return;
	}

	if (fValidateOnly) return;

	// STEP TWO:  Set up the temp file to write to.

	AutoSGPFile f(GCM->tempFiles()->openForWriting(mapFileName, true));

	f->write(&sSectorY, 2);

	// STEP THREE:  Save the data

	// This works for both civs and enemies
	SaveSoldierInitListLinks(f);

	f->write(&sSectorX, 2);

	// This check may appear confusing.  It is intended to abort if the player is
	// saving the game.  It is only supposed to preserve the links to the
	// placement list, so when we finally do leave the level with enemies
	// remaining, we will need the links that are only added when the map is
	// loaded, and are normally lost when restoring a save.
	if (gTacticalStatus.uiFlags & LOADING_SAVED_GAME)
	{
		slots = 0;
	}

	f->write(&slots, 4);

	UINT32 const timestamp = GetWorldTotalMin();
	f->write(&timestamp, 4);

	f->write(&bSectorZ, 1);

	// If we are saving the game, we don't need to preserve the soldier
	// information, just preserve the links to the placement list.
	if (!(gTacticalStatus.uiFlags & LOADING_SAVED_GAME))
	{
		for (INT32 i = first; i <= last; ++i)
		{
			SOLDIERTYPE const& s = GetMan(i);
			// CJC: note that bInSector is not required; the civ could be offmap!
			if (!s.bActive || s.bLife == 0 || s.ubProfile != NO_PROFILE)
				continue;

			// Soldier is valid, so find the matching soldier init list entry for modification.
			SOLDIERINITNODE const* const curr = FindSoldierInitNodeBySoldier(s);
			if (!curr)
				continue;

			SOLDIERCREATE_STRUCT const* const dp = curr->pDetailedPlacement;
			InjectSoldierCreateIntoFile(f, dp);
			// Insert a checksum equation (anti-hack)
			UINT16 const checksum = CalcSoldierCreateCheckSum(dp);
			f->write(&checksum, 2);
		}

		UINT8 const sector_id = SECTOR(sSectorX, sSectorY);
		f->write(&sector_id, 1);
	}

	SetSectorFlag(sSectorX, sSectorY, bSectorZ, file_flag);
}