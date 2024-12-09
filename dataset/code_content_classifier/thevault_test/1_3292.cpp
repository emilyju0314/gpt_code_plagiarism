void CExplorerWnd::OnFilterOpts()
{
	if (ctl_filter_opts_.m_nMenuResult == 0x7FFF)
	{
		// Edit filters option - fire up options dlg at filters page
		theApp.display_options(FILTER_OPTIONS_PAGE, TRUE);
	}
	else if (ctl_filter_opts_.m_nMenuResult != 0)
	{
		// Get the filter string corresp. to the menu item selected
		CString filters = theApp.GetCurrentFilters();
		CString ss;
		AfxExtractSubString(ss, filters, (ctl_filter_opts_.m_nMenuResult-1)*2 + 1, '|');

		// Use the new filter
		ctl_filter_.SetWindowText(ss);
		VERIFY(UpdateData());
		list_.SetFilter(curr_filter_);

		AddFilter();

		Refresh();
	}
}