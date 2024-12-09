void CAerialView::invalidate_addr_range_boundary(FILE_ADDRESS start_addr, FILE_ADDRESS end_addr)
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

	// If we have a small number of lines to invalidate we just do
	// normal invalidation (see 2 in note above).
	if (start_line + 3 >= end_line)
	{
		invalidate_addr_range(start_addr, end_addr, true);  // Don't invalidate the border as it hasn't changed
		return;
	}

	// Invalidate and draw the four sides.
	// Note that we call UpdateWindow to force an immediate redraw otherwise Windows
	// combines them into one big rect which is slow (like invalidate_addr_range).
	// Also note that the marching ants can now be up to 4 pixels wide which
	// explains the offsets of 4 below.

	// Top
	rct.left   = bdr_left_;
	rct.right  = bdr_left_ + cols_*actual_dpix_;
	rct.top    = bdr_top_ + start_line*actual_dpix_;
	rct.bottom = rct.top + actual_dpix_ + 4;
	InvalidateRect(&rct, FALSE);
	UpdateWindow();
	// Bottom
	rct.left   = bdr_left_;
	rct.right  = bdr_left_ + cols_*actual_dpix_;
	rct.top    = bdr_top_ + end_line*actual_dpix_ - 4;
	rct.bottom = bdr_top_ + (end_line+1)*actual_dpix_;
	InvalidateRect(&rct, FALSE);
	UpdateWindow();
	// Left
	rct.left   = bdr_left_;
	rct.right  = rct.left + 4;
	rct.top    = bdr_top_ + start_line*actual_dpix_;
	rct.bottom = bdr_top_ + (end_line+1)*actual_dpix_;
	InvalidateRect(&rct, FALSE);
	UpdateWindow();
	// Right
	rct.right  = bdr_left_ + cols_*actual_dpix_;
	rct.left   = rct.right - 4;                         // 4 pixels less than right
	rct.top    = bdr_top_ + start_line*actual_dpix_;
	rct.bottom = bdr_top_ + (end_line+1)*actual_dpix_;
	InvalidateRect(&rct, FALSE);
	UpdateWindow();
}