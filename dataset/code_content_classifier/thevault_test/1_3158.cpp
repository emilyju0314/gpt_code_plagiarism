void CHexEditView::calc_autofit()
{
	CRect cli;
	CRectAp rect;           // Client rectangle in norm. coords
	GetDisplayRect(&cli);
	rect = ConvertFromDP(cli) - GetScroll();
	ASSERT(rect.left == 0 && rect.top == 0);

	// Work out how many columns we can display across the window
	// NOTE: These calcs are directly related to the calcs in hex_pos and char_pos

	// Work out width of display area (total minus address area width)
	int daw = rect.right - addr_width_*text_width_ - text_width_/2 - 1;
	if (display_.vert_display)
	{
		int group_offset = (daw/text_width_w_)%(group_by_ + 1);
		if (group_offset == 0) group_offset = group_by_;
		rowsize_ = ((daw/text_width_w_ - 1)/(group_by_ + 1)) * group_by_ + group_offset;

		// Make sure scroll bars are not shown
		ASSERT(rowsize_ < 5 || rect.right >= char_pos(rowsize_-1)+text_width_w_);
	}
	else if (display_.char_area && display_.hex_area)
	{
		int sec_len = group_by_*(3*text_width_ + text_width_w_) + text_width_;
		int group_offset = (daw % sec_len)/(3*text_width_ + text_width_w_);
		if (group_offset == group_by_) group_offset = 0;
		rowsize_ = ((daw + text_width_) / sec_len) * group_by_ + group_offset;
		ASSERT(rowsize_ < 5 || rect.right >= char_pos(rowsize_-1)+text_width_w_);
	}
	else if (display_.char_area)
	{
		// This is easy as char area has no grouping
		rowsize_ = daw/text_width_w_;
		ASSERT(rowsize_ < 5 || rect.right >= char_pos(rowsize_-1)+text_width_w_);
	}
	else
	{
		ASSERT(display_.hex_area);
		display_.hex_area = TRUE; // defensive
		//rowsize_ = (daw - daw/(3*group_by_+1))/(3*text_width_);
		int group_offset = (daw/text_width_ - 2)%(3*group_by_ + 1);
		if (group_offset == 3*group_by_) group_offset--;

		rowsize_ = ((daw/text_width_ - 2)/(3*group_by_ + 1))*group_by_ + group_offset/3 + 1;
		ASSERT(rowsize_ < 5 || rect.right >= hex_pos(rowsize_-1)+2*text_width_);
	}

	// Must display at least 4 columns & no more than buffer can hold
	if (rowsize_ < 4)
		rowsize_ = 4;
	else if (rowsize_ > max_buf)
		rowsize_ = max_buf;

#if 0 // now done after returns in recalc_display()
	offset_ = rowsize_ - (rowsize_ + real_offset_ - 1) % rowsize_ - 1;
#endif
}