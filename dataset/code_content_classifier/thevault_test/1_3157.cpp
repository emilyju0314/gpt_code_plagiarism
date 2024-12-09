void CHexEditView::recalc_display()
{
	// Stop re-entry (can cause inf. recursion)
	if (in_recalc_display) return;
	in_recalc_display = true;

	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());

	if (GetScrollPastEnds() != theApp.scroll_past_ends_)
	{
		SetScrollPastEnds(theApp.scroll_past_ends_);
		SetScroll(GetScroll());
	}
	SetAutoscroll(theApp.autoscroll_accel_);

	// Save info on the current font
	{
		TEXTMETRIC tm;
		CClientDC dc(this);
		OnPrepareDC(&dc);
		dc.GetTextMetrics(&tm);
		text_height_ = tm.tmHeight + tm.tmExternalLeading; // Height of font

		first_char_ = tm.tmFirstChar;                   // 1st valid char of font

		last_char_ = tm.tmLastChar;                     // last valid char of font
// This causes problems when in IBM/OEM mode since these fonts have characters right down to zero
//        if (first_char_ < 32) first_char_ = 32;         // Some fonts return 30 but 30,31 are nothing

// The max char width returned by many fonts is much too big (seems to be bigger than any character in font!?)
//      text_width_ = tm.tmMaxCharWidth;                // width of widest char in font
		CSize size;
		::GetTextExtentPoint32(dc.m_hDC, "D", 1, &size);
		text_width_ = size.cx;                  // width of "D"
		::GetTextExtentPoint32(dc.m_hDC, "W", 1, &size);
		text_width_w_ = size.cx;                  // width of "W"

		if (display_.vert_display)
			line_height_ = text_height_ * 3;
		else
			line_height_ = text_height_;
	}

	// Adjust border for ruler
	bdr_top_ = 0;
	if (theApp.ruler_)
	{
		if (display_.hex_addr)
			bdr_top_ += text_height_;  // one row of text for hex offsets
		if (display_.decimal_addr || display_.line_nums)
			bdr_top_ += text_height_;  // one row of text for dec offsets
		bdr_top_ += 5;                 // allow room for a thin line
	}
#ifdef TEST_CLIPPING
	bdr_top_ += 40;
#endif

	FILE_ADDRESS length = GetDocument()->length() + display_.addrbase1;

	hex_width_ = display_.hex_addr ? SigDigits(length, 16) : 0;
	dec_width_ = display_.decimal_addr ? SigDigits(length) : 0;

	num_width_ = 0;
	calc_addr_width();
	if (display_.autofit && display_.line_nums)
	{
		// If autofit is on then rowsize_ and num_width_ are mutually dependent so
		// we have to handle this carefully.
		int prev_rowsize = 4;

		// Loop a few timres and see if the value converges
		for (int ii = 0; ii < 10; ++ii)
		{
			num_width_ = SigDigits(length/prev_rowsize);
			calc_addr_width();
			calc_autofit();
			if (rowsize_ == prev_rowsize)
				break;
			prev_rowsize = rowsize_;
		}
		// If it didn't converge then favour the larger value
		// (I think non-convergence only occurs when the row
		// size oscillates between 2 adjacent integer values.)
		if (rowsize_ < prev_rowsize)
			rowsize_ = prev_rowsize;
	}
	else if (display_.autofit)
		calc_autofit();
	else if (display_.line_nums)
	{
		num_width_ = SigDigits(length/rowsize_);
		calc_addr_width();
	}

	// Ensure offset is within valid range after recalc of rowsize_
	offset_ = rowsize_ - (rowsize_ + real_offset_ - 1) % rowsize_ - 1;

	// Fit columns to window width?
	if (display_.autofit)
	{
		// Work out the current address of the caret/selection
		FILE_ADDRESS start_addr, end_addr;
		GetSelAddr(start_addr, end_addr);
		int row = 0;
		if (start_addr == end_addr && display_.vert_display)
			row = pos2row(GetCaret());

		// Set size before setting scroll/caret to avoid them being moved to "valid" pos
		if (display_.vert_display)
			SetTSize(CSizeAp(-1, ((GetDocument()->length() + offset_)/rowsize_ + 1)*3));  // 3 rows of text
		else
			SetTSize(CSizeAp(-1, (GetDocument()->length() + offset_)/rowsize_ + 1));

		// Make sure scroll position is at left side
//        SetScroll(CPointAp(0, topleft/rowsize_ * line_height_));
		SetScroll(CPointAp(0, GetScroll().y));

		// Move the caret/selection to the where the same byte(s) as before
		SetSel(addr2pos(start_addr, row), addr2pos(end_addr, row));
	}
	else
	{
		if (display_.vert_display)
			SetTSize(CSizeAp(-1, ((GetDocument()->length() + offset_)/rowsize_ + 1)*3));  // 3 rows of text
		else
			SetTSize(CSizeAp(-1, (GetDocument()->length() + offset_)/rowsize_ + 1));
	}

	// Make sure we know the width of the display area
	if (display_.vert_display || display_.char_area)
		SetSize(CSize(char_pos(rowsize_-1)+text_width_w_+text_width_w_/2+1, -1));
	else
	{
		ASSERT(display_.hex_area);
		display_.hex_area = TRUE; // defensive
		SetSize(CSize(hex_pos(rowsize_-1)+2*text_width_+text_width_/2+1, -1));
	}

	if (pcv_ != NULL)
		pcv_->recalc_display();

	in_recalc_display = false;
}