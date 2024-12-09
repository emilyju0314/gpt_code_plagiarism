BOOL CCompareView::MovePos(UINT nChar, UINT nRepCnt,
						 BOOL control_down, BOOL shift_down, BOOL caret_on)
{
	FILE_ADDRESS start_addr, end_addr;
	BOOL end_base = GetSelAddr(start_addr, end_addr);   // Is selection base at end of selection?
	int row = 0;
	if (start_addr == end_addr && phev_->display_.vert_display)
		row = pos2row(GetCaret());
	FILE_ADDRESS new_address;

	// Start with start of (or end of, if moving forwards) current selection
	if (shift_down)
	{
		// Work out which end of selection is being extended
		if (end_base)
			new_address = start_addr;
		else
			new_address = end_addr;
		//++shift_moves_;
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
			// Work out how many groups there are to start of file
			long gpr = (phev_->rowsize_ - 1)/phev_->group_by_ + 1;    // groups per row
			FILE_ADDRESS groups = ((new_address + phev_->offset_)/phev_->rowsize_) * gpr +
						  ((new_address + phev_->offset_)%phev_->rowsize_ + phev_->group_by_ - 1)/phev_->group_by_;
			// Calculate the group to move to and address of 1st byte
			groups -= nRepCnt;
			new_address = (groups/gpr) * phev_->rowsize_ - phev_->offset_ + (groups%gpr) * phev_->group_by_;
		}
		else
		{
			new_address -= nRepCnt;
		}
		break;
	case VK_RIGHT:
		if (control_down)
		{
			// First work out how many groups there are to start of file
			long gpr = (phev_->rowsize_ - 1)/phev_->group_by_ + 1;    // groups per row
			FILE_ADDRESS groups = ((new_address + phev_->offset_)/phev_->rowsize_) * gpr +
						  ((new_address + phev_->offset_)%phev_->rowsize_)/phev_->group_by_;
			// Calculate the group to move to
			groups += nRepCnt;
			new_address = (groups/gpr) * phev_->rowsize_ - phev_->offset_ + (groups%gpr) * phev_->group_by_;
		}
		else
		{
			new_address += nRepCnt;
		}
		break;
	case VK_UP:
		if (phev_->display_.vert_display && !shift_down)
		{
			new_address -= phev_->rowsize_ * ((2 - row + nRepCnt)/3);
			row = (3333 + row - nRepCnt)%3;   // Add a large number div. by 3 to make sure % operand is +ve
		}
		else
			new_address -= phev_->rowsize_ * nRepCnt;
		break;
	case VK_DOWN:
		if (phev_->display_.vert_display && !shift_down)
		{
			new_address += phev_->rowsize_ * ((row + nRepCnt)/3);
			row = (row + nRepCnt)%3;
		}
		else
			new_address += phev_->rowsize_ * nRepCnt;
		break;
	case VK_HOME:
		if (control_down)
		{
			new_address = 0;
		}
		else
		{
			new_address = ((new_address + phev_->offset_)/phev_->rowsize_) * phev_->rowsize_ - phev_->offset_;
		}
		break;
	case VK_END:
		if (control_down)
		{
			new_address = GetDocument()->CompLength();
		}
		else
		{
			new_address = ((new_address + phev_->offset_)/phev_->rowsize_ + 1) * phev_->rowsize_ - phev_->offset_ - 
								(shift_down ? 0 : 1);
		}
		break;
	case VK_PRIOR:
		GetSize(tt, pp, ll);
		new_address -= phev_->rowsize_ * (pp.cy/phev_->line_height_) * nRepCnt;
		break;
	case VK_NEXT:
		GetSize(tt, pp, ll);
		new_address += phev_->rowsize_ * (pp.cy/phev_->line_height_) * nRepCnt;
		break;
	default:
		return CScrView::MovePos(nChar, nRepCnt, control_down, shift_down, caret_on);
	}

	if (new_address < 0)
	{
		new_address = 0;
		row = 0;
	}
	else if (new_address > GetDocument()->CompLength())
	{
		new_address = GetDocument()->CompLength();
		if (phev_->display_.vert_display && !shift_down)
			row = 2;
	}

	// Scroll addresses into view if moved to left column of hex area or 
	// left column of char area when no hex area displayed
	if ((new_address + phev_->offset_) % phev_->rowsize_ == 0 &&
		(phev_->display_.vert_display || !phev_->display_.edit_char || !phev_->display_.hex_area))
	{
		SetScroll(CPointAp(0,-1));
	}

	if (shift_down && end_base)
	{
		MoveToAddress(end_addr, new_address);
	}
	else if (shift_down)
	{
		MoveToAddress(start_addr, new_address);
	}
	else
		MoveToAddress(new_address, -1, row);

	return TRUE;                // Indicate that keystroke used
}