void CAerialView::invalidate_addr_range(FILE_ADDRESS start_addr, FILE_ADDRESS end_addr, bool no_border /*=false*/)
{
	CHexEditDoc *pDoc = GetDocument();
	int width = GetDocument()->GetBpe() * cols_;

	// Restrict to just what is in the display then convert to window device coords
	if (start_addr < scrollpos_) start_addr = scrollpos_;
	if (end_addr > scrollpos_ + width*rows_) end_addr = scrollpos_ + width*rows_;

	// Work out the elts we are invalidating offset from the elt at the top-left
	int start_elt = int((start_addr - scrollpos_)/GetDocument()->GetBpe());
	int end_elt   = int((end_addr - 1 - scrollpos_)/GetDocument()->GetBpe() + 1);
	if (start_elt >= end_elt)
		return;                         // Nothing to invalidate or all outside display

	// Work out line range that needs invalidating
	int start_line = int(start_elt/cols_);
	int end_line   = int(end_elt/cols_);

	CRect rct;

	// If start and end on the same line just invalidate between them
	if (start_line == end_line)
	{
		rct.left   = bdr_left_ + (start_elt%cols_)*actual_dpix_;
		rct.right  = bdr_left_ + (end_elt%cols_)*actual_dpix_;
		rct.top    = bdr_top_ + start_line*actual_dpix_;
		rct.bottom = rct.top + actual_dpix_;
		InvalidateRect(&rct);
		if (!no_border)
		{
			rct.left = 0; rct.right = bdr_left_;    // Do left border too
			InvalidateRect(&rct);
		}
		return;
	}
	// Invalidate partial lines at each end
	rct.left   = bdr_left_ + (start_elt%cols_)*actual_dpix_;
	rct.right  = bdr_left_ + cols_*actual_dpix_;
	rct.top    = bdr_top_ + start_line*actual_dpix_;
	rct.bottom = rct.top + actual_dpix_;
	InvalidateRect(&rct);
	if (!no_border)
	{
		rct.left = 0; rct.right = bdr_left_;        // Do left border too
		InvalidateRect(&rct);
	}

	rct.left   = bdr_left_;
	rct.right  = bdr_left_ + (end_elt%cols_)*actual_dpix_;
	rct.top    = bdr_top_ + end_line*actual_dpix_;
	rct.bottom = rct.top + actual_dpix_;
	InvalidateRect(&rct);
	if (!no_border)
	{
		rct.left = 0; rct.right = bdr_left_;  // Do left border too
		InvalidateRect(&rct);
	}

	// If more than one line between start and end then invalidate that block too
	if (start_line + 1 < end_line)
	{
		rct.left   = bdr_left_;
		rct.right  = bdr_left_ + cols_*actual_dpix_;
		rct.top    = bdr_top_ + start_line*actual_dpix_;
		rct.bottom = bdr_top_ + end_line*actual_dpix_;
		InvalidateRect(&rct);
		if (!no_border)
		{
			rct.left = 0; rct.right = bdr_left_;
			InvalidateRect(&rct);
		}
	}
}