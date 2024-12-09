CString DeviceName(CString name) // TODO get rid of this (use SpecialList::name() instead)
{
	CString retval;
	if (name.Left(17) == _T("\\\\.\\PhysicalDrive"))
		retval = _T("Physical Drive ") + name.Mid(17);
	else if (name.Left(9) == _T("\\\\.\\CdRom"))
		retval = _T("Optical Drive ") + name.Mid(9);
	else if (name.Left(10) == _T("\\\\.\\Floppy"))
		retval = _T("Floppy Drive ") + name.Mid(10);
#if 0
	if (name.Left(14) == _T("\\device\\Floppy"))
		retval.Format("Floppy Drive %d", atoi(name.Mid(14)));
	else if (name.Left(16) == _T("\\device\\Harddisk"))
		retval.Format("Hard Drive %d", atoi(name.Mid(16)));
	else if (name.Left(13) == _T("\\device\\Cdrom"))
		retval.Format("Optical Drive %d", atoi(name.Mid(13)));
#endif
	//else if (name.Left(17) == _T("\\\\.\\PhysicalDrive"))
	//	return _T("Physical Drive ") + name.Mid(17);
	//else if (name.Left(9) == _T("\\\\.\\CdRom"))
	//	return _T("Optical Drive ") + name.Mid(9);
	//else if (name == _T("\\\\.\\a:"))
	//	return CString(_T("Floppy Drive 0"));
	//else if (name == _T("\\\\.\\b:"))
	//	return CString(_T("Floppy Drive 1"));
	else if (name.GetLength() == 6)
	{
		_TCHAR vol[4] = _T("?:\\");     // Vol name used for volume enquiry calls
		vol[0] = name[4];

		// Find out what sort of drive it is
		retval.Format(_T(" (%c:)"), vol[0]);
		switch (::GetDriveType(vol))
		{
		default:
			ASSERT(0);
			break;
		case DRIVE_NO_ROOT_DIR:
		case DRIVE_REMOVABLE:
			if (vol[0] == 'A' || vol[0] == 'B')
				retval = "Floppy Drive " + retval;
			else
				retval = "Removable " + retval;
			break;
		case DRIVE_FIXED:
			retval = "Fixed Drive " + retval;
			break;
		case DRIVE_REMOTE:
			retval = "Network Drive " + retval;
			break;
		case DRIVE_CDROM:
			retval = "Optical Drive " + retval;
			break;
		case DRIVE_RAMDISK:
			retval = "RAM Drive " + retval;
			break;
		}
	}
	else
		ASSERT(0);

	return retval;
}