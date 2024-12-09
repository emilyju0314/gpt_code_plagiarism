static void HandleMilitiaDefections(INT16 sMapX, INT16 sMapY)
{
	UINT8 ubRank;
	UINT8 ubMilitiaCnt;
	UINT8 ubCount;
	UINT32 uiChanceToDefect;

	for( ubRank = 0; ubRank < MAX_MILITIA_LEVELS; ubRank++ )
	{
		ubMilitiaCnt = MilitiaInSectorOfRank(sMapX, sMapY, ubRank);

		// check each guy at each rank to see if he defects
		for (ubCount = 0; ubCount < ubMilitiaCnt; ubCount++)
		{
			switch( ubRank )
			{
				case GREEN_MILITIA:
					uiChanceToDefect = 50;
					break;
				case REGULAR_MILITIA:
					uiChanceToDefect = 75;
					break;
				case ELITE_MILITIA:
					uiChanceToDefect = 90;
					break;
				default:
					SLOGA("HandleMilitiaDefections: invalid Rank");
					return;
			}

			// roll the bones; should I stay or should I go now?  (for you music fans out there)
			if (Random(100) < uiChanceToDefect)
			{
				//B'bye!  (for you SNL fans out there)
				StrategicRemoveMilitiaFromSector(sMapX, sMapY, ubRank, 1);
			}
		}
	}
}