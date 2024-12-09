void CExplorerWnd::AddFilter()
{
	int ii, count = ctl_filter_.GetCount();
	CString tmp = curr_filter_;
	tmp.MakeUpper();  // Get uppercase version for case-insensitive compare

	// See if it is already there
	for (ii = 0; ii < count; ++ii)
	{
		CString ss;
		ctl_filter_.GetLBText(ii, ss);
		ss.MakeUpper();
		if (tmp == ss)
		{
			// Delete it from the list so we can add it at the top (below)
			ctl_filter_.DeleteString(ii);
			break;
		}
	}
	ctl_filter_.InsertString(0, curr_filter_);
}