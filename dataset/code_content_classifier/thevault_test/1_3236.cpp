BOOL GetDataPath(CString &data_path, int csidl /*=CSIDL_APPDATA*/)
{
	BOOL retval = FALSE;
	LPTSTR pbuf = data_path.GetBuffer(MAX_PATH);

	LPMALLOC pMalloc;
	if (SUCCEEDED(SHGetMalloc(&pMalloc)))
	{
		ITEMIDLIST *itemIDList;
		if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, csidl, &itemIDList)))
		{
			SHGetPathFromIDList(itemIDList, pbuf);
			pMalloc->Free(itemIDList);
			retval = TRUE;
		}
		pMalloc->Release();
	}

	data_path.ReleaseBuffer();
	if (!retval)
		data_path.Empty();     // Make string empty if we failed just in case
	else if (csidl == CSIDL_APPDATA || csidl == CSIDL_COMMON_APPDATA)
		data_path += '\\' + CString(AfxGetApp()->m_pszRegistryKey) + 
					 '\\' + CString(AfxGetApp()->m_pszProfileName) +
					 '\\';
	return retval;
}