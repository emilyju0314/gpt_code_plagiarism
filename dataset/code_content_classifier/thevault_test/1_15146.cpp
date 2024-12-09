static void StrategicPromoteMilitiaInSector(INT16 const x, INT16 const y, UINT8 const current_rank, UINT8 const n)
{
	SECTORINFO& si = SectorInfo[SECTOR(x, y)];

	Assert(si.ubNumberOfCivsAtLevel[current_rank] >= n);
	//KM : July 21, 1999 patch fix
	if (si.ubNumberOfCivsAtLevel[current_rank] < n) return;

	si.ubNumberOfCivsAtLevel[current_rank    ] -= n;
	si.ubNumberOfCivsAtLevel[current_rank + 1] += n;

	fMapPanelDirty = TRUE;
}