void CExplorerWnd::OnSelchangeFilter()
{
	ASSERT(ctl_filter_.GetCurSel() > -1);
	CString ss;
	// Get the filter that was selected and put it into the control
	// [For some reason when a new item is selected from the drop down list the
	//  previous string is still in the control when we get this message.]
	ctl_filter_.GetLBText(ctl_filter_.GetCurSel(), ss);
	ctl_filter_.SetWindowText(ss);

	VERIFY(UpdateData());
	list_.SetFilter(curr_filter_);

	Refresh();
}