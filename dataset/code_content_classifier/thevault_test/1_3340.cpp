void CAerialView::get_disp_params(int &rows, int &cols, int &actual_dpix)
{
	// Get the actual display area
	CRect rct;
	GetClientRect(&rct);
	rct.DeflateRect(bdr_left_, bdr_top_, bdr_right_, bdr_bottom_);

	// Increase the actual display pixel size if the whole file fits in the 
	// display areas up to as big as 7 x 7.
	for (actual_dpix = disp_.dpix; actual_dpix <= MAX_DPIX; ++actual_dpix)
	{
		int tmp = cols = (rct.Width()/(8*actual_dpix)) * 8;
		if (cols < 8)
			cols = 8;
		else if (cols > CHexEditDoc::MAX_WIDTH)
			cols = CHexEditDoc::MAX_WIDTH;
		rows = rct.Height()/actual_dpix;
		if (rows < 1) rows = 1;

		// Check if we have expanded the width too far since we always have at least 8 columns
		if (tmp == 0 || !theApp.auto_aerial_zoom_)
			break;

		// Check if we have expanded the size so it would no longer fit in the window
		if ((GetDocument()->NumElts()-1) / cols + 1 > rows)
			break;
	}
	if (actual_dpix > disp_.dpix)
	{
		// Reduce back to the size that fits
		--actual_dpix;
		cols = (rct.Width()/(8*actual_dpix)) * 8;
		if (cols < 8)
			cols = 8;
		else if (cols > CHexEditDoc::MAX_WIDTH)
			cols = CHexEditDoc::MAX_WIDTH;
		rows = rct.Height()/actual_dpix;
		if (rows < 1) rows = 1;
	}

	// Adjust scrollbar scaling factor as scroll bars seem to be limited to signed 16 bit numbers
	int endy = int((GetDocument()->length()-1)/(GetDocument()->GetBpe() * cols_) + 1);
	// Make sure vertical dimensions do not overflow a signed 32 bit int as
	// the bitmap cannot handle it.
	ASSERT(endy < INT_MAX);
	sbfact_ = endy/30000 + 1;

	ASSERT(rows > 0 && cols > 7);
	ASSERT(actual_dpix >= disp_.dpix && actual_dpix <= MAX_DPIX);
}