void CHexEditView::do_mouse(CPoint dev_down, CSizeAp doc_dist)
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());

	CPointAp doc_down = ConvertFromDP(dev_down);  // Sel start point converted from device to doc coords
	CPointAp doc_up(doc_down);                    // Point where selection ends = start +
	doc_up += doc_dist;                         // ... distance of selection

	// Convert selection (doc coords) to addresses and make sure in valid range
	FILE_ADDRESS start_addr, end_addr;
	FILE_ADDRESS length = GetDocument()->length();
	start_addr = pos2addr(doc_down);
	end_addr = pos2addr(doc_up);

	if (start_addr < 0) start_addr = 0; else if (start_addr > length) start_addr = length;
	if (end_addr < 0) end_addr = 0; else if (end_addr > length) end_addr = length;

	// Save undo information
	FILE_ADDRESS prev_start, prev_end;
	GetSelAddr(prev_start, prev_end);
	int prev_row = 0;
	if (prev_start == prev_end && display_.vert_display)
		prev_row = pos2row(GetCaret());

	if (start_addr == prev_start && end_addr == prev_end)  // exactly the same selection
		return;

	BOOL saved_area = display_.edit_char;
	if (!display_.vert_display && display_.char_area && display_.hex_area) // If both areas displayed ...
		display_.edit_char = pos_hex(doc_down.x, FALSE) >= rowsize_;       // sel may swap between areas
	undo_.push_back(view_undo(undo_move));
	undo_.back().address = prev_start | (FILE_ADDRESS(prev_row)<<62);
	if (prev_start != prev_end)
	{
		// Save the previous selection
		undo_.push_back(view_undo(undo_sel));
		undo_.back().address = prev_end;
	}
	if (display_.edit_char != saved_area)
	{
		// Allow more buffer if editing hex
		if (display_.edit_char)
			SetHorzBufferZone(1);
		else
			SetHorzBufferZone(2);
		// Save the fact that we swapped between areas
		undo_.push_back(view_undo(undo_state, TRUE));
		undo_.back().disp_state = disp_state_;
	}

	SetSel(addr2pos(start_addr), addr2pos(end_addr), true);

	if (aa->highlight_)
		add_highlight(start_addr, end_addr, TRUE);

	nav_save(start_addr, end_addr, "Mouse Click (Play) ");
}