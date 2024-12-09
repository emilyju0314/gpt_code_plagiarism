void CHexEditView::invalidate_hex_addr_range(FILE_ADDRESS start_addr, FILE_ADDRESS end_addr)
{
	CRect cli;                          // Client rectangle in device coords
	CRectAp inv;                        // The rectangle to actually invalidate (doc coords)
	CRectAp disp_rect;                  // Rectangle of display in our coords
	GetDisplayRect(&cli);
	disp_rect = ConvertFromDP(cli);

	// Work out the addresses of the first and (one past) the last byte in display
	FILE_ADDRESS start_disp = (disp_rect.top/line_height_)*rowsize_ - offset_;
	FILE_ADDRESS end_disp = (disp_rect.bottom/line_height_ + 1)*rowsize_ - offset_;

	// Reduce address range to relevant (displayed) area
	if (start_addr < start_disp) start_addr = start_disp;
	if (end_addr > end_disp) end_addr = end_disp;

	if (start_addr >= end_addr)
		return;                         // Nothing to invalidate or all outside display

	// Work out line range that needs invalidating
	FILE_ADDRESS start_line = (start_addr + offset_)/rowsize_;
	FILE_ADDRESS end_line = (end_addr + offset_)/rowsize_;

	// If start and end on the same line just invalidate between them
	if (start_line == end_line)
	{
		ASSERT(display_.hex_area || display_.char_area);
		if (!display_.vert_display && display_.hex_area)
		{
			// Note: (23/11/03) go back an extra text_width_ bytes to allow for 
			// deletion mark (tracking changes) before the byte
			inv = CRectAp(hex_pos(int((start_addr+offset_)%rowsize_)) - text_width_, start_line * line_height_,
						  hex_pos(int((end_addr+offset_)%rowsize_)) + 1, (start_line + 1) * line_height_ + 1);
			CRect dev = ConvertToDP(inv);
			DoInvalidateRect(&dev);
		}
		if (display_.vert_display || display_.char_area)
		{
			// Note: (23/11/03) go back an extra 2 pixels to allow for 
			// deletion mark (tracking changes) before the byte
			inv = CRectAp(char_pos(int((start_addr+offset_)%rowsize_)) - 2, start_line * line_height_,
						  char_pos(int((end_addr+offset_)%rowsize_)) + 1, (start_line + 1) * line_height_ + 1);
			CRect dev = ConvertToDP(inv);
			DoInvalidateRect(&dev);
		}
		return;
	}

	// Start line is before end line: invalidate partial lines at each end
	ASSERT(display_.hex_area || display_.char_area);
	if (!display_.vert_display && display_.hex_area)
	{
		// Hex area
		inv = CRectAp(hex_pos(int((start_addr+offset_)%rowsize_))-text_width_, start_line * line_height_,
					  hex_pos(int(rowsize_)) + 1, (start_line + 1) * line_height_ + 1);
		CRect dev = ConvertToDP(inv);
		DoInvalidateRect(&dev);

		inv = CRectAp(hex_pos(0)-text_width_, end_line * line_height_,
					  hex_pos(int((end_addr+offset_)%rowsize_)) + 1, (end_line + 1) * line_height_ + 1);
		dev = ConvertToDP(inv);
		DoInvalidateRect(&dev);
	}
	if (display_.vert_display || display_.char_area)
	{
		// Char area or vert_display
		inv = CRectAp(char_pos(int((start_addr+offset_)%rowsize_))-2, start_line * line_height_,
					  char_pos(int(rowsize_)), (start_line + 1) * line_height_);
		CRect dev = ConvertToDP(inv);
		DoInvalidateRect(&dev);

		inv = CRectAp(char_pos(0)-2, end_line * line_height_,
					  char_pos(int((end_addr+offset_)%rowsize_)), (end_line + 1) * line_height_);
		dev = ConvertToDP(inv);
		DoInvalidateRect(&dev);
	}

	// If more than one line between start and end then invalidate that block too
	if (start_line + 1 < end_line)
	{
		ASSERT(display_.hex_area || display_.char_area);
		if (!display_.vert_display && display_.hex_area)
		{
			inv = CRectAp(hex_pos(0)-text_width_, (start_line + 1) * line_height_,
						hex_pos(rowsize_) + 1, (end_line) * line_height_ + 1);
			CRect dev = ConvertToDP(inv);
			DoInvalidateRect(&dev);
		}
		if (display_.vert_display || display_.char_area)
		{
			inv = CRectAp(char_pos(0)-2, (start_line + 1) * line_height_,
						char_pos(rowsize_) + 1, (end_line) * line_height_ + 1);
			CRect dev = ConvertToDP(inv);
			DoInvalidateRect(&dev);
		}
	}
}