void CExplorerWnd::OnSelchangeFolderName()
{
	ASSERT(ctl_name_.GetCurSel() > -1);
	CString ss;
	// Get the folder name that was selected and put it into the control
	// [For some reason when a new item is selected from the drop down list the
	//  previous string is still in the control when we get this message.]
	ctl_name_.GetLBText(ctl_name_.GetCurSel(), ss);
	ctl_name_.SetWindowText(ss);

	VERIFY(UpdateData());
	list_.add_to_hist_ = false;
	list_.DisplayFolder(curr_name_);
	list_.add_to_hist_ = true;

	Refresh();
}