INT8 GetSAMIdFromSector(INT16 sSectorX, INT16 sSectorY, INT8 bSectorZ)
{
	// check if valid sector
	if (bSectorZ != 0)
	{
		return(-1);
	}

	// get the sector value
	INT16 sSectorValue = SECTOR(sSectorX, sSectorY);
	return GCM->findSamIDBySector(sSectorValue);
}