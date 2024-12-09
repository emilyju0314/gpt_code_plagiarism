INT16 GetMineSectorForTown(INT8 const town_id)
{
	for (auto m : GCM->getMines())
	{
		if (m->associatedTownId != town_id) continue;
		return SECTOR_INFO_TO_STRATEGIC_INDEX(m->entranceSector);
	}
	return -1;
}