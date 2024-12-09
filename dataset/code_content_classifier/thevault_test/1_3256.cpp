bool CHexEditDoc::MakeTempFile()
{
	if (!tempFileA_.IsEmpty() && _access(tempFileA_, 0) != -1)
		return true;    // temp file already present when swapping between tab/split views

	char temp_dir[_MAX_PATH];
	char temp_file[_MAX_PATH];
	CWaitCursor wc;     // displays Hour glass until destroyed on function exit
	if (pfile1_ == NULL ||
		!::GetTempPath(sizeof(temp_dir), temp_dir) ||
		!::GetTempFileName(temp_dir, _T("_HE"), 0, temp_file) ||
		!::CopyFile(pfile1_->GetFilePath(), temp_file, FALSE))
	{
		return false;
	}
	tempFileA_ = temp_file;
	return true;
}