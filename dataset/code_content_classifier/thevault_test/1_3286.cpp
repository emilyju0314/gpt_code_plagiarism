void CExplorerWnd::UpdateFolderInfo(CString folder)
{
	ctl_name_.SetWindowText(folder);

	if (hh_ != 0)
	{
		::FindCloseChangeNotification(hh_);
		hh_ = 0;
	}
	hh_ = ::FindFirstChangeNotification(folder, FALSE,
										FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME |
										FILE_NOTIFY_CHANGE_ATTRIBUTES | FILE_NOTIFY_CHANGE_SIZE |
										FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_CREATION);
}