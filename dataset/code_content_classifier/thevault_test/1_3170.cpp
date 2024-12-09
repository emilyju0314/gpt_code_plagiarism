BOOL CHexEditView::MovePos(UINT nChar, UINT nRepCnt,
						 BOOL control_down, BOOL shift_down, BOOL caret_on)
{
	// CScrView::MovePos scrolling behaviour is OK
	if (!caret_on)
		return CScrView::MovePos(nChar, nRepCnt, control_down, shift_down, caret_on);

	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
	if (aa->recording_)
	{
		long vv = nChar;
		if (control_down) vv |= 0x10000;
		if (shift_down)   vv |= 0x20000;
		for (UINT ii = 0; ii < nRepCnt; ++ii)
			aa->SaveToMacro(km_key, vv);
	}

	FILE_ADDRESS start_addr, end_addr;
	BOOL end_base = GetSelAddr(start_addr, end_addr);   // Is selection base at end of selection?
	int row = 0;
	if (start_addr == end_addr && display_.vert_display)
		row = pos2row(GetCaret());
	FILE_ADDRESS new_address;
	CString desc("Cursor key");

	// Start with start of (or end of, if moving forwards) current selection
	if (shift_down)
	{
		// Work out which end of selection is being extended
		if (end_base)
			new_address = start_addr;
		else
			new_address = end_addr;
		++shift_moves_;
	}
	else if (start_addr == end_addr )
		new_address = start_addr;                       // No current selection
	else if (nChar == VK_DOWN || nChar == VK_NEXT)
		new_address = end_addr;                         // Move from char after selection
	else if (nChar == VK_RIGHT || nChar == VK_END)
		new_address = end_addr - 1;                     // Move from last char of selection
	else
		new_address = start_addr;                       // Move from start of selection

	CSizeAp tt, pp, ll;                   // Size of document total,page,line

	switch (nChar)
	{
	case VK_LEFT:
		if (control_down)
		{
			desc = "Ctrl + Left Arrow";
			// Work out how many groups there are to start of file
			long gpr = (rowsize_ - 1)/group_by_ + 1;    // groups per row
			FILE_ADDRESS groups = ((new_address+offset_)/rowsize_) * gpr +
						  ((new_address+offset_)%rowsize_ + group_by_ - 1)/group_by_;
			// Calculate the group to move to and address of 1st byte
			groups -= nRepCnt;
			new_address = (groups/gpr) * rowsize_ - offset_ + (groups%gpr) * group_by_;
		}
		else
		{
			desc = "Left Arrow";
			new_address -= nRepCnt;
		}
		break;
	case VK_RIGHT:
		if (control_down)
		{
			desc = "Ctrl + Right Arrow";
			// First work out how many groups there are to start of file
			long gpr = (rowsize_ - 1)/group_by_ + 1;    // groups per row
			FILE_ADDRESS groups = ((new_address+offset_)/rowsize_) * gpr +
						  ((new_address+offset_)%rowsize_)/group_by_;
			// Calculate the group to move to
			groups += nRepCnt;
			new_address = (groups/gpr) * rowsize_ - offset_ + (groups%gpr) * group_by_;
		}
		else
		{
			desc = "Right Arrow";
			new_address += nRepCnt;
		}
		break;
	case VK_UP:
		desc = "Up Arrow";
		if (display_.vert_display && !shift_down)
		{
			new_address -= rowsize_ * ((2 - row + nRepCnt)/3);
			row = (3333 + row - nRepCnt)%3;   // Add a large number div. by 3 to make sure % operand is +ve
		}
		else
			new_address -= rowsize_ * nRepCnt;
		break;
	case VK_DOWN:
		desc = "Down Arrow";
		if (display_.vert_display && !shift_down)
		{
			new_address += rowsize_ * ((row + nRepCnt)/3);
			row = (row + nRepCnt)%3;
		}
		else
			new_address += rowsize_ * nRepCnt;
		break;
	case VK_HOME:
		if (control_down)
		{
			desc = "Ctrl + Home key ";  // space at end means significant nav pt
			new_address = 0;
		}
		else
		{
			desc = "Home key";
			new_address = ((new_address+offset_)/rowsize_) * rowsize_ - offset_;
		}
		break;
	case VK_END:
		if (control_down)
		{
			desc = "Ctrl + End key ";  // space at end means significant nav pt
			new_address = GetDocument()->length();
		}
		else
		{
			desc = "End key";
			new_address = ((new_address+offset_)/rowsize_ + 1) * rowsize_ - offset_ - 
								(shift_down ? 0 : 1);
		}
		break;
	case VK_PRIOR:
		desc = "Page Up";
		GetSize(tt, pp, ll);
		new_address -= rowsize_ * (pp.cy/line_height_) * nRepCnt;
		break;
	case VK_NEXT:
		desc = "Page Down";
		GetSize(tt, pp, ll);
		new_address += rowsize_ * (pp.cy/line_height_) * nRepCnt;
		break;
	default:
		return CScrView::MovePos(nChar, nRepCnt, control_down, shift_down, caret_on);
	}

	if (new_address < 0)
	{
		new_address = 0;
		row = 0;
		aa->mac_error_ = 2;
	}
	else if (new_address > GetDocument()->length())
	{
		new_address = GetDocument()->length();
		if (display_.vert_display && !shift_down)
			row = 2;
		aa->mac_error_ = 2;
	}

	// Scroll addresses into view if moved to left column of hex area or 
	// left column of char area when no hex area displayed
	if ((new_address + offset_) % rowsize_ == 0 && (display_.vert_display || !display_.edit_char || !display_.hex_area))
		SetScroll(CPointAp(0,-1));

	if (shift_down && end_base)
	{
		MoveWithDesc("Shift + " + desc, end_addr, new_address);

		// Handle this when shift key released now (in OnKeyUp)
//        if (aa->highlight_)
//            add_highlight(new_address, end_addr, TRUE);
	}
	else if (shift_down)
	{
		MoveWithDesc("Shift + " + desc, start_addr, new_address);

		// Handle this when shift key released now (in OnKeyUp)
//        if (aa->highlight_)
//            add_highlight(start_addr, new_address, TRUE);
	}
	else
		MoveWithDesc(desc, new_address, -1, -1, -1, FALSE, FALSE, row);

	return TRUE;                // Indicate that keystroke used
}