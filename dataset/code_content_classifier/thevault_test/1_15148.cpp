static bool ServeNextFriendlySectorInTown(INT16* const neighbour_x, INT16* const neighbour_y)
{
	while (g_town_sectors[gubTownSectorServerIndex].town != BLANK_SECTOR)
	{
		INT32 const sector = g_town_sectors[gubTownSectorServerIndex++].sector;

		// if this sector is in the town we're looking for
		if (StrategicMap[SECTOR_INFO_TO_STRATEGIC_INDEX(sector)].bNameId != gubTownSectorServerTownId) continue;

		INT16 const x = SECTORX(sector);
		INT16 const y = SECTORY(sector);

		// Make sure we're not supposed to skip it
		if (x == gsTownSectorServerSkipX && y == gsTownSectorServerSkipY) continue;

		// check if it's "friendly" - not enemy controlled, no enemies in it, no combat in progress
		if (!SectorOursAndPeaceful(x, y, 0)) continue;

		*neighbour_x = x;
		*neighbour_y = y;
		return true;
	}
	return false;
}