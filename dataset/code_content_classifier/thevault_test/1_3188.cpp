void CHexEditView::do_shift_mouse(CPoint dev_down, CSizeAp doc_dist)
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());

	CPointAp doc_down = ConvertFromDP(dev_down); // Left down point converted from device to doc coords
	CPointAp doc_up(doc_down);                   // Point of left button up (doc coords) = ...
	doc_up += doc_dist;                          // ... doc_down + length of selection

	// Convert selection (doc coords) to addresses and make sure in valid range
	FILE_ADDRESS start_addr, end_addr;                  // New selection range
	FILE_ADDRESS prev_start, prev_end;                  // Previous selection range
	FILE_ADDRESS length = GetDocument()->length();
//    GetSelAddr(start_addr, prev_end);
	if (GetSelAddr(prev_start, prev_end))
		start_addr = prev_end;                  // Base of previous selection was end
	else
		start_addr = prev_start;
	end_addr = pos2addr(doc_up);

	if (start_addr < 0) start_addr = 0; else if (start_addr > length) start_addr = length;
	if (end_addr < 0) end_addr = 0; else if (end_addr > length) end_addr = length;

	if (end_addr != prev_end)
	{
		// Save the previous selection for undo
		undo_.push_back(view_undo(undo_move));
		undo_.back().address = start_addr;
		undo_.push_back(view_undo(undo_sel));
		undo_.back().address = prev_end;

		// Extend the selection
		SetSel(addr2pos(start_addr), addr2pos(end_addr), true);

		if (aa->highlight_)
			add_highlight(start_addr, end_addr, TRUE);
	}
	nav_save(start_addr, end_addr, "Mouse Click (Play) ");
}