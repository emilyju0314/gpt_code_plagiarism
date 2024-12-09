void CHexEditApp::GetXMLFileList()
{
	CFileFind ff;

	xml_file_name_.clear();

	ASSERT(xml_dir_.Right(1) == "\\");
	BOOL bContinue = ff.FindFile(xml_dir_ + _T("*.XML"));

	while (bContinue)
	{
		// At least one match - check them all
		bContinue = ff.FindNextFile();

		xml_file_name_.push_back(ff.GetFileTitle());
	}
}