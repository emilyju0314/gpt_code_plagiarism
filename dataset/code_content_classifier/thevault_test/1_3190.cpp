void CHexEditView::OnStartLine()
{
	num_entered_ = num_del_ = num_bs_ = 0;  // Turn off any consec edits
	FILE_ADDRESS start_addr, end_addr;
	GetSelAddr(start_addr, end_addr);
	int row = 0;
	if (start_addr == end_addr && display_.vert_display)
		row = pos2row(GetCaret());

	// Check if offset has actually changed
	if (real_offset_ != start_addr)
	{
		undo_.push_back(view_undo(undo_offset));
		undo_.back().rowsize = real_offset_;        // Save previous offset for undo
		real_offset_ = (int)start_addr;
		//offset_ = rowsize_ - (rowsize_ + real_offset_ - 1) % rowsize_ - 1;

		recalc_display();
		SetSel(addr2pos(start_addr, row), addr2pos(end_addr, row));
		DoInvalidate();
		((CHexEditApp *)AfxGetApp())->SaveToMacro(km_start_line);
	}
	else
	{
		((CMainFrame *)AfxGetMainWnd())->StatusBarText("Warning: offset not changed");
		((CHexEditApp *)AfxGetApp())->mac_error_ = 1;
	}
}