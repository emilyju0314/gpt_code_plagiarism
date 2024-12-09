void CHexEditView::OnCopyHex()
{
	// Get the addresses of the selection
	FILE_ADDRESS start, end;
	GetSelAddr(start, end);
	ASSERT(start >= 0 && start <= end && end <= GetDocument()->length());

	// Clipboard setup and error checking
	if (!copy2cb_init(start, end))
		return;

	CWaitCursor wait;                           // Turn on wait cursor (hourglass)

	bool ok = copy2cb_hextext(start, end);

	if (::CloseClipboard() && ok)
	{
		theApp.ClipBoardAdd((end - start)*3);
		theApp.SaveToMacro(km_copy_hex);
	}
	else
		theApp.mac_error_ = 20;
}