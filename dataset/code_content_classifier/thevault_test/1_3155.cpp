BOOL CHexEditView::check_ro(const char *desc)
{
	CString ss;
	FILE_ADDRESS start_addr, end_addr;
	GetSelAddr(start_addr, end_addr);

	if (display_.readonly && GetDocument()->read_only())
	{
		ss.Format("This file cannot be modified as it is open for read only.\n\n"
				  "For this reason you cannot %s.", desc);
		TaskMessageBox("File is read only", ss);
		CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
		aa->mac_error_ = 10;
		return TRUE;
	}
	else if (pdfv_ != NULL && pdfv_->ReadOnly(start_addr, end_addr))
	{
		ss.Format("The selection contains one or "
				  "more read-only template fields, "
				  "hence you can't %s.", desc);
		TaskMessageBox("Read only field", ss);
		theApp.mac_error_ = 10;
		return TRUE;
	}
	else if (display_.readonly)
	{
		ss.Format("You can't %s while this window is read only.\n\n"
				  "Do you want to turn off read only mode?", desc);
		if (AvoidableTaskDialog(IDS_READ_ONLY, ss, NULL, NULL, TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON) != IDOK)
		{
			CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
			aa->mac_error_ = 10;
			return TRUE;
		}
		else
			allow_mods();
	}
	return FALSE;  // We were or now are in RW mode and there are no RO template fields in the selection
}