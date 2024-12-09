__int64 AvailableSpace(const char *filename)
{
	// First work out the volume that the file is on
	char vol[128] = "";
	if (isalpha(filename[0]) && filename[1] == ':')
	{
		// Normal file name
		vol[0] = filename[0];
		strcpy(vol + 1, _T(":\\"));
	}
	else if (filename[0] == '\\' && filename[1] == '\\')
	{
		// UNC file name (eg \\MyServer\MyShare\MyFile)
		// Find 4th backslash and copy everything up to it
		const char *pp = strchr(filename + 2, '\\');      // 3rd
		if (pp != NULL) pp = strchr(pp + 1, '\\');    // 4th

		if (pp != NULL && pp - filename + 1 < sizeof(vol) / sizeof(*vol))
		{
			// Copy just the volume part
			strncpy(vol, filename, pp - filename + 1);
			vol[pp - filename + 1] = '\0'; // terminate the string
		}
	}
	else
		return -1;   // Bad file name?

	// Now try some Windows system calls to get the free space
	ULARGE_INTEGER bytes_avail, dummy1, dummy2;
	DWORD SectorsPerCluster;
	DWORD BytesPerSector;
	DWORD NumberOfFreeClusters;
	DWORD TotalNumberOfClusters;

	// Get free space on drive and make sure there is enough
	if (::GetDiskFreeSpaceEx(vol, &bytes_avail, &dummy1, &dummy2))
	{
		return bytes_avail.QuadPart;
	}
	else if (::GetDiskFreeSpace(vol,
		&SectorsPerCluster,
		&BytesPerSector,
		&NumberOfFreeClusters,
		&TotalNumberOfClusters))
	{
		return BytesPerSector * (__int64)SectorsPerCluster * NumberOfFreeClusters;
	}
	else
		return -1;
}