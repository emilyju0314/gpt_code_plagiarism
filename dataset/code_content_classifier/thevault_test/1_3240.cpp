int DeviceVolume(LPCTSTR filename)
{
	const char *dev_str;                // Start of device name that we are looking for
	UINT drive_type;                    // Type of drive looking for
	int dev_num;                        // The device number we are looking for

	if (_tcsncmp(filename, _T("\\\\.\\PhysicalDrive"), 17) == 0)
	{
		drive_type = DRIVE_REMOVABLE;
		dev_num = atoi(filename + 17);
		dev_str = "\\device\\Harddisk";
	}
	else if (_tcsncmp(filename, _T("\\\\.\\CdRom"), 9) == 0)
	{
		drive_type = DRIVE_CDROM;
		dev_num = atoi(filename + 9);
		dev_str = "\\device\\Cdrom";
	}
	//else if (_tcsncmp(filename, _T("\\\\.\\Floppy"), 10) == 0)
	//{
	//	dev_num = atoi(filename + 10);
	//	dev_str = "\\device\\Floppy";
	//}
	else
	{
		ASSERT(0);  // invalid physical device name
		return -1;
	}

	// First scan all volumes (A: to Z:) for drives of the desired type
	DWORD dbits = GetLogicalDrives();   // Bit is on for every drive present
	char vol[4] = "?:\\";               // Vol name used for volume enquiry calls
	for (int ii = 0; ii < 26; ++ii)
	{
		vol[0] = 'A' + (char)ii;
		if ((dbits & (1<<ii)) != 0 && ::GetDriveType(vol) == drive_type)
		{
			char dev[3] = "?:";
			dev[0] = 'A' + (char)ii;
			char buf[128];
			buf[0] = '\0';
			::QueryDosDevice(dev, buf, sizeof(buf));  // eg \device\cdrom0
			int offset = strlen(dev_str);
			if (_strnicmp(buf, dev_str, offset) == 0 &&
				isdigit(buf[offset]) &&
				atoi(buf + offset) == dev_num)
			{
				return ii;
			}
		}
	}
	return -1;
}