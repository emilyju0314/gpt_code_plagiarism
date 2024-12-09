void AddProfilesUsingProfileInsertionData()
{
	for (const MercProfile* prof : GCM->listMercProfiles())
	{
		if (!prof->isNPCorRPC() && !prof->isVehicle())   continue;

		// Perform various checks to make sure the soldier is actually in the same
		// sector, alive and so on. More importantly, the flag to use profile
		// insertion data must be set.
		ProfileID                i = prof->getID();
		MERCPROFILESTRUCT const& p = prof->getStruct();
		if (p.sSectorX != gWorldSectorX)                 continue;
		if (p.sSectorY != gWorldSectorY)                 continue;
		if (p.bSectorZ != gbWorldSectorZ)                continue;
		if (p.ubMiscFlags & PROFILE_MISC_FLAG_RECRUITED) continue;
		if (p.ubMiscFlags & PROFILE_MISC_FLAG_EPCACTIVE) continue;
		if (p.bLife == 0)                                continue;
		if (!p.fUseProfileInsertionInfo)                 continue;

		SOLDIERTYPE* ps = FindSoldierByProfileID(i);
		if (!ps)
		{
			// Create a new soldier, as this one doesn't exist
			SOLDIERCREATE_STRUCT c;
			c = SOLDIERCREATE_STRUCT{};
			c.bTeam     = CIV_TEAM;
			c.ubProfile = i;
			c.sSectorX  = gWorldSectorX;
			c.sSectorY  = gWorldSectorY;
			c.bSectorZ  = gbWorldSectorZ;
			ps = TacticalCreateSoldier(c);
			if (!ps) continue; // XXX exception?
		}
		SOLDIERTYPE& s = *ps;

		// Insert the soldier
		s.ubStrategicInsertionCode = p.ubStrategicInsertionCode;
		s.usStrategicInsertionData = p.usStrategicInsertionData;
		UpdateMercInSector(s, gWorldSectorX, gWorldSectorY, gbWorldSectorZ);

		// check action ID values
		if (p.ubQuoteRecord != 0)
		{
			s.ubQuoteRecord   = p.ubQuoteRecord;
			s.ubQuoteActionID = p.ubQuoteActionID;
			if (s.ubQuoteActionID == QUOTE_ACTION_ID_CHECKFORDEST)
			{
				// Gridno will have been changed to destination, so we're there
				NPCReachedDestination(&s, FALSE);
			}
		}

		// Make sure this person's pointer is set properly in the init list
		if (SOLDIERINITNODE* const init = FindSoldierInitListNodeByProfile(s.ubProfile))
		{
			init->pSoldier    = &s;
			init->ubSoldierID = s.ubID;
			// Also connect schedules here
			SOLDIERCREATE_STRUCT& dp = *init->pDetailedPlacement;
			if (dp.ubScheduleID != 0)
			{
				if (SCHEDULENODE* const sched = GetSchedule(dp.ubScheduleID))
				{
					sched->soldier = &s;
					s.ubScheduleID = dp.ubScheduleID;
				}
			}
		}
	}
}