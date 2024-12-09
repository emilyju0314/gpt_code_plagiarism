void CHexEditView::do_replace(FILE_ADDRESS start, FILE_ADDRESS end, unsigned char *pp, size_t len)
{
	// Can't replace if view is read only
	if (check_ro("replace bytes"))
		return;

	num_entered_ = num_del_ = num_bs_ = 0;      // Stop any editing

	ASSERT(start < end && end <= GetDocument()->length());
	if (display_.overtype && end-start != len)
	{
		// xxx direct warning if GetDocument()->IsDevice()?
		if (AvoidableTaskDialog(IDS_REPLACE_OVERTYPE,
								"The Replace operation requires replacing bytes with data of a "
								   "different length.  This requires the window to be in insert mode."
								   "\n\nDo you want to turn off overtype mode?",
								NULL, NULL, 
								TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON) != IDOK)
		{
			theApp.mac_error_ = 10;
			return;
		}
		else if (!do_insert())
			return;
	}

	if (display_.overtype || end-start == len)
	{
		GetDocument()->Change(mod_replace, start, len, pp, 0, this);
	}
	else
	{
		GetDocument()->Change(mod_delforw, start, end-start, NULL, 0, this);
		if (len > 0)
			GetDocument()->Change(mod_insert, start, len, pp, 0, this, TRUE);
	}
	int row = 0;
	if (display_.vert_display) row = pos2row(GetCaret());
	SetSel(addr2pos(start+len, row), addr2pos(start+len, row));
	DisplayCaret();
	show_prop();                            // Make sure dialogs don't obscure our changes
	show_pos();                             // Update tool bar
}