void CExplorerWnd::build_filter_menu()
{
	CString filters = theApp.GetCurrentFilters();
	if (filters == filters_)
		return;

	CMenu mm;
	mm.CreatePopupMenu();
	CString filter_name;
	for (int filter_num = 0;
		 AfxExtractSubString(filter_name, filters, filter_num*2, '|') && !filter_name.IsEmpty();
		 ++filter_num)
	{
		// Store filter and use index as menu item ID (but add 1 since 0 means no ID used).
		mm.AppendMenu(MF_STRING, filter_num+1, filter_name);
	}
	mm.AppendMenu(MF_SEPARATOR);
	mm.AppendMenu(MF_STRING, 0x7FFF, _T("&Edit Filter List..."));
	ctl_filter_opts_.m_hMenu = mm.GetSafeHmenu();
	mm.Detach();

	filters_ = filters;
}