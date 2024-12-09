CString CHistoryShellList::GetAttributes(LPCTSTR path, bool * p_is_dir /*=NULL*/)
{
	CString retval;
	if (p_is_dir != NULL)
		*p_is_dir = false;
	DWORD attr = GetFileAttributes(path);

	if (attr == INVALID_FILE_ATTRIBUTES)
	{
		// GetFileAttributes() may fail on locked files like PAGEFILE.SYS,
		// so the backup is to use FindFirstFile (slower alternative)
		WIN32_FIND_DATA wfd;
		if (FindFirstFile(path, &wfd) == INVALID_HANDLE_VALUE)
			attr = -1;
		else
			attr = wfd.dwFileAttributes;
	}
	if (attr != -1)
	{
		if ((attr & FILE_ATTRIBUTE_DIRECTORY) != 0 && p_is_dir != NULL)
			*p_is_dir = true;

		if ((attr & FILE_ATTRIBUTE_READONLY) != 0)
			retval += _T("R");
		if ((attr & FILE_ATTRIBUTE_HIDDEN) != 0)
			retval += _T("H");
		if ((attr & FILE_ATTRIBUTE_SYSTEM) != 0)
			retval += _T("S");
		if ((attr & FILE_ATTRIBUTE_ARCHIVE) != 0)
			retval += _T("A");
		if (theApp.show_not_indexed_)
		{
			if ((attr & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) != 0)  // not-indexed flag is on
				retval += _T("N");
		}
		else
		{
			if ((attr & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) == 0)  // not-indexed flag is off = indexed
				retval += _T("I");
		}
		if ((attr & FILE_ATTRIBUTE_COMPRESSED) != 0)
			retval += _T("C");
		if ((attr & FILE_ATTRIBUTE_ENCRYPTED) != 0)
			retval += _T("E");
	}
	return retval;
}