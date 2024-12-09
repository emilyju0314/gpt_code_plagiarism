BOOL CHexEditDoc::DoSave(LPCTSTR lpszPathName, BOOL bReplace)
{
	BOOL modified = IsModified();
	if (modified) SetModifiedFlag(FALSE);                    // This gets rid of " *" from default filename
	preview_file_fif_ = FREE_IMAGE_FORMAT(-999);             // force reload of info (when needed) since the file changed
	BOOL retval = CDocument::DoSave(lpszPathName, bReplace);
	if (!retval && modified) SetModifiedFlag();              // If not saved restore modified status

	if (!retval && theApp.mac_error_ < 2) theApp.mac_error_ = 2;
	return retval;
}