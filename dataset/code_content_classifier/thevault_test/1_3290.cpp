void CExplorerWnd::Update(LPCTSTR file_name /* = NULL */)
{
	if (update_required_)
		return;                 // Update already flagged

	if (file_name == NULL)
		update_required_ = true;
	else
	{
		// Get the name of the folder containing the file
		CString ss(file_name);
		::PathRemoveFileSpec(ss.GetBuffer(1));
		ss.ReleaseBuffer();

		// If the file's folder is the folder we are displaying then remember that we need to refresh it
		if (AfxComparePath(ss, list_.Folder()))
			update_required_ = true;
	}
}