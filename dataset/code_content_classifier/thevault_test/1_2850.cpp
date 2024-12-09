DriveArray* CameraToDVDDlg::GetAllDrives()
{
	if (!m_pDvdPlugin)
	{
		return NULL;
	}

	DriveArray* pDrives = new DriveArray;

	const int size = 2048;
	WCHAR drives[size];
	memset(drives, 0, size); 
	GetLogicalDriveStrings(size - sizeof(WCHAR),drives);
	WCHAR* p = drives;
	while (*p)
	{
		if (DRIVE_CDROM == GetDriveType(p))
		{
			char letter = (char)p[0];
			VRDevice* pDevice = m_pDvdPlugin->createOpticalDiscDevice(letter, FALSE);
			if(pDevice)
			{
				pDrives->Items.push_back(new DriveItem(pDevice));
			}
		}
		p += 4;
	}

	if (pDrives->Items.size() == 0)
	{
		delete pDrives;
		pDrives = NULL;
	}

	return pDrives;
}