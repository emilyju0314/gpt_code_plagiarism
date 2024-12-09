void InitNewCampaign()
{
	//First clear all the sector information of all enemy existance.  Conveniently, the
	//ubGroupType is also cleared, which is perceived to be an empty group.
	std::fill_n(SectorInfo, 256, SECTORINFO{});
	InitStrategicMovementCosts();
	RemoveAllGroups();

	InitKnowFacilitiesFlags( );

	BuildUndergroundSectorInfoList();

	if (gamepolicy(reveal_start_sector))
	{
		// Allow overhead view of start sector on game onset.
		UINT16 uiStartSector = gamepolicy(start_sector);
		SetSectorFlag(SECTORX(uiStartSector), SECTORY(uiStartSector), 0, SF_ALREADY_VISITED);
	}
	//Generates the initial forces in a new campaign.  The idea is to randomize numbers and sectors
	//so that no two games are the same.
	InitStrategicAI();

	InitStrategicStatus();

}