BSTR GetPhysicalDeviceName(LPCTSTR name)
{
	CString dev_name;

	if (_tcsncmp(name, _T("\\\\.\\PhysicalDrive"), 17) == 0)
		dev_name.Format(_T("\\device\\Harddisk%d\\Partition0"), atoi(name + 17));
	else if (_tcsncmp(name, _T("\\\\.\\CdRom"), 9) == 0)
		dev_name.Format(_T("\\device\\Cdrom%d"), atoi(name + 9));
	else if (_tcsncmp(name, _T("\\\\.\\Floppy"), 10) == 0)
		dev_name.Format(_T("\\device\\Floppy%d"), atoi(name + 10));
	else
		ASSERT(0);

	// Return as a BSTR (so Unicode string is available)
	return dev_name.AllocSysString();
}