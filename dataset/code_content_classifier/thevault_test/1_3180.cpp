void CHexEditView::show_pos(FILE_ADDRESS address /*=-1*/, BOOL no_dffd /*=FALSE*/)
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
	if (address != -2 && aa->refresh_off_) return;

	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();
	CString ss;         // String to hold text of edit box

	FILE_ADDRESS end;
	if (address < 0)
		GetSelAddr(address, end);
	else
		end = address;

#if 0 // BCG (this is handled by calls to AfxGetApp()->OnIdle(0) in searches/compares)
	// Set the hex address edit box
	if (aa->hex_ucase_)
		ss.Format("%lX", address);
	else
		ss.Format("%lx", address);
	mm->hec_hex_addr_.SetWindowText(ss);
	mm->hec_hex_addr_.add_spaces();
	mm->hec_hex_addr_.UpdateWindow();           // Force immed. redraw

	// Set the decimal address edit box
	ss.Format("%lu", address);
	mm->dec_dec_addr_.SetWindowText(ss);
	mm->dec_dec_addr_.add_commas();
	mm->dec_dec_addr_.UpdateWindow();           // Force immed. redraw
#else
//    TRACE1("---- Address set to %ld\n", long(address));
	((CMainFrame *)AfxGetMainWnd())->SetAddress(address);  // for ON_UPDATE_COMMAND_UI to fix displayed addresses
#endif
	// Move to corresponding place in other views if sync on
	if (pdfv_ != NULL && !no_dffd && display_.auto_sync_dffd)
		pdfv_->SelectAt(address);
	if (pav_ != NULL && display_.auto_sync_aerial)
		pav_->ShowPos(address);
	if (pcv_ != NULL && GetDocument()->CompareDifferences() > -1 && display_.auto_sync_comp)
	{
		display_.auto_sync_comp = 0;        // turn off to stop problems
		pcv_->MoveToAddress(GetDocument()->GetCompAddress(address), GetDocument()->GetCompAddress(end));
		display_.auto_sync_comp = 1;        // turn back on
	}
}