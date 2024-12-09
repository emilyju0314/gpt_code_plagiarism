void CExplorerWnd::AddFolder()
{
	int ii, count = ctl_name_.GetCount();
	CString tmp = list_.Folder();
	tmp.MakeUpper();  // Get uppercase version for case-insensitive compare

	// See if it is already there
	for (ii = 0; ii < count; ++ii)
	{
		CString ss;
		ctl_name_.GetLBText(ii, ss);
		ss.MakeUpper();
		if (tmp == ss)
		{
			// Delete it from the list so we can add it to the top (below)
			ctl_name_.DeleteString(ii);
			break;
		}
	}
	ctl_name_.InsertString(0, list_.Folder());  // Add original string (with case)
}