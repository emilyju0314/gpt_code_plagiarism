void CExplorerWnd::NewFolder()
{
	VERIFY(UpdateData());

	if (curr_name_.IsEmpty())
		return;

	// Change current folder
	CString dir;
	if (!list_.GetCurrentFolder(dir) || curr_name_ != dir)
		list_.DisplayFolder(curr_name_);

	Refresh();
}