void CAerialView::draw_ants(CDC* pDC, FILE_ADDRESS start_addr, FILE_ADDRESS end_addr, COLORREF clr)
{
	int width = GetDocument()->GetBpe() * cols_;
	ASSERT(scrollpos_ % width == 0);

	if (end_addr <= scrollpos_ || start_addr >= scrollpos_ + width*rows_)
		return;  // all outside the display

	// We draw ants in 2 colours so they are visible on any background colour
	COLORREF clr1, clr2;
	get_colours(clr, clr1, clr2);

	// Constrain  the addresses to those that might affect the display.
	// (We need to go a row above and below the actual displayed rows.)
	if (start_addr < scrollpos_ - width) start_addr = scrollpos_ - width;
	if (end_addr > scrollpos_ + width*(rows_+1)) end_addr = scrollpos_ + width*(rows_+1);

	t1_.restart();
	if (actual_dpix_ == 1 && end_addr - start_addr < 2*width)
		draw_lines(pDC, start_addr, end_addr, clr1, clr2);       // Just draw a row of ants as there's not even 2 rows of pixels
	else
		draw_bounds(pDC, start_addr, end_addr, clr1, clr2);
	t1_.stop();
}