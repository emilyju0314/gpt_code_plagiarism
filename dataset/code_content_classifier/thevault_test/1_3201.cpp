void CHexEditView::OnSwapMark()
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
//    if (!aa->playing_ && GetFocus() != this) SetFocus(); // Ensure focus does not stay in DlgBar
	num_entered_ = num_del_ = num_bs_ = 0;      // Stop any editing

	FILE_ADDRESS start_addr, end_addr;
	BOOL end_base = GetSelAddr(start_addr, end_addr);
	int row = 0;
	if (start_addr == end_addr && display_.vert_display)
		row = pos2row(GetCaret());

	// If same address and mark/caret are in same areas (both in hex or both in char area) return
	if (mark_ == start_addr && start_addr == end_addr && 
		(display_.vert_display || !display_.char_area || !display_.hex_area || display_.edit_char == display_.mark_char))
	{
		// There is nothing to do
		aa->mac_error_ = 1;
		return;
	}

	// If the caret and the mark are in different areas we have to swap them
	if (!display_.vert_display && 
		display_.char_area && display_.hex_area && 
		display_.edit_char != display_.mark_char)
	{
		undo_.push_back(view_undo(undo_state));        // save undo for edit_char_ and mark_char_
		undo_.back().disp_state = disp_state_;
		display_.edit_char = !display_.edit_char;
		display_.mark_char = !display_.mark_char;
		if (display_.edit_char)
			SetHorzBufferZone(1);
		else
			SetHorzBufferZone(2);

		// We need to specify the previous address since otherwise MoveToAddress
		// will use the current selection which is now in the wrong area since
		// display_.edit_char has changed.
		MoveWithDesc("Swap Cursor with Mark ", mark_, mark_, start_addr, end_addr, TRUE);

		// Need to call SetSel in case MoveToAddress did not due to no move (only area swap)
		SetSel(addr2pos(mark_), addr2pos(mark_), true);
	}
	else
		MoveWithDesc("Swap Cursor with Mark ", mark_, -1, -1, -1, FALSE, FALSE, row);

	// Move the mark
	undo_.push_back(view_undo(undo_setmark, TRUE));     // save undo for move mark
	undo_.back().address = mark_;
	invalidate_addr_range(mark_, mark_ + 1);            // force undraw of mark
	mark_ = start_addr;
	invalidate_addr_range(mark_, mark_ + 1);            // force draw of new mark
	if (theApp.align_rel_ && mark_ != GetDocument()->base_addr_)
	{
		// mark moved and current search is relative to mark so restart bg search
		GetDocument()->StopSearch();
		GetDocument()->base_addr_ = GetSearchBase();
		GetDocument()->StartSearch();
	}

	aa->SaveToMacro(km_swap_mark);
}