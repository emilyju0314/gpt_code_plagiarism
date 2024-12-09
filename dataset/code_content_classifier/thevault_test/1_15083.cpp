static std::unique_ptr<AutoSGPFile> OpenMapModificationTempFile(INT16 const sSectorX, INT16 const sSectorY, INT8 const bSectorZ)
{
	SetSectorFlag(sSectorX, sSectorY, bSectorZ, SF_MAP_MODIFICATIONS_TEMP_FILE_EXISTS);

	return std::make_unique<AutoSGPFile>(GCM->tempFiles()->openForAppend(GetMapTempFileName(SF_MAP_MODIFICATIONS_TEMP_FILE_EXISTS, sSectorX, sSectorY, bSectorZ)));
}