void CHexEditApp::OnNewUser()
{
	CString dstFolder;
	if (!::GetDataPath(dstFolder))
		return;       // no point in continuing (Win95?)

	CString dstFile = dstFolder + FILENAME_DTD;

	// If DTD file exists, probably just the registry settings were deleted so don't ask
	// if we want to copy (but copy over files if not already there
	if (::_access(dstFile, 0) == -1 &&
		TaskMessageBox("New User",
					  "This is the first time you have run this version of HexEdit.\n\n"
					  "Do you want to set up you own personal copies of templates and macros?",
					  MB_YESNO) == IDYES)
	{
		CopyUserFiles();
	}
}