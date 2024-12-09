void BuildUndergroundSectorInfoList()
{
	TrashUndergroundSectorInfo();

	for (auto ugInfo : GCM->getUndergroundSectors())
	{
		AddUndergroundNode(ugInfo, gGameOptions.ubDifficultyLevel);
	}
}