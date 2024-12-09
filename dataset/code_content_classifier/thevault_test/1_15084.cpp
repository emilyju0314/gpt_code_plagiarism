static void SaveModifiedMapStructToMapTempFile(MODIFY_MAP const* const pMap, INT16 const sSectorX, INT16 const sSectorY, INT8 const bSectorZ)
{
	std::unique_ptr<AutoSGPFile> hFile = OpenMapModificationTempFile(sSectorX, sSectorY, bSectorZ);
	SaveModifiedMapStructToMapTempFile(pMap, *hFile);
}