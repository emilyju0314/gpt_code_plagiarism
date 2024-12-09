bool CHexEditView::copy2cb_init(FILE_ADDRESS start, FILE_ADDRESS end)
{
	num_entered_ = num_del_ = num_bs_ = 0;      // Stop any editing

	// Check for problems with selection size
	if (start == end)
	{
		ASSERT(theApp.playing_);  // Macro might have recorded Copy but when played there is no selection
		// Copy to clipboard while nothing selected, presumably in macro playback
		TaskMessageBox("Nothing selected",
			"Copying to the clipboard uses the current selection.  "
			"As there is no selection, nothing was copied.");
		theApp.mac_error_ = 10;
		return false;
	}
	if (end-start > 8000000L)
	{
		CString ss;
		ss.Format("Do you really want to put %sbytes on\n"
				  "the clipboard?  This may take some time.",
				  NumScale(double(end-start)));
		if (TaskMessageBox("Large Clipboard Size Warning", ss, MB_YESNO) != IDYES)
		{
			theApp.mac_error_ = 5;
			return false;
		}
	}
	// Now open and empty the clipboard ready for copying data into
	if (!OpenClipboard())
	{
		AfxMessageBox("The clipboard is in use!");
		theApp.mac_error_ = 10;
		return false;
	}
	if (!::EmptyClipboard())
	{
		AfxMessageBox("Could not delete previous contents of the clipboard!");
		::CloseClipboard();
		theApp.mac_error_ = 10;
		return false;
	}
	return true;
}