static void AddOpenableStructStatusToMapTempFile(UINT32 uiMapIndex, BOOLEAN fOpened, AutoSGPFile& hFile)
{
	MODIFY_MAP Map;

	Map = MODIFY_MAP{};

	Map.usGridNo = (UINT16)uiMapIndex;
	Map.usImageType = fOpened;

	Map.ubType = SLM_OPENABLE_STRUCT;

	SaveModifiedMapStructToMapTempFile(&Map, hFile);
}