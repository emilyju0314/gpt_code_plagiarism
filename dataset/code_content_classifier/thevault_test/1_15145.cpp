static void StrategicAddMilitiaToSector(INT16 sMapX, INT16 sMapY, UINT8 ubRank, UINT8 ubHowMany)
{
	SECTORINFO *pSectorInfo = &( SectorInfo[ SECTOR( sMapX, sMapY ) ] );

	pSectorInfo->ubNumberOfCivsAtLevel[ ubRank ] += ubHowMany;

	// update the screen display
	fMapPanelDirty = TRUE;
}