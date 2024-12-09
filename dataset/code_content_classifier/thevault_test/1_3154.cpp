BOOL CHexEditView::check_ovr(const char *desc)
{
	if (!display_.overtype)
		return FALSE;         // already in INS mode

	CString ss;
	ss.Format("You can't %s while in overtype mode.", desc);

	// First check if we can turn on INS mode
	if (display_.readonly)
	{
		TaskMessageBox("Not Allowed in OVR Mode",
			ss + "\n\nAlso note that you can't turn on insert mode when the file is read only.");
		theApp.mac_error_ = 10;
		return TRUE;
	}
	if (GetDocument()->IsDevice())
	{
		TaskMessageBox("Not Allowed in OVR Mode",
			ss + "\n\nAlso note that you can't turn on insert mode for devices (logical volumes and physical disks).");
		theApp.mac_error_ = 10;
		return TRUE;
	}

	if (AvoidableTaskDialog(IDS_OVERTYPE,
							ss + "\n\nDo you want to turn off OVR mode?",
							"\nThe operation may insert or delete bytes from the file "
								"which is not permitted in overtype mode.\n\n"
								"Select \"OK\" to turn on insert (INS) mode.",
							NULL, 
							TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON) != IDOK)
	{
		theApp.mac_error_ = 5;
		return TRUE;
	}
	else if (!do_insert())
		return TRUE;

	return FALSE;  // return FALSE to indicate we are no longer in OVR mode
}