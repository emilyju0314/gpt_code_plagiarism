bool CHexEditView::over_rowsize_adjuster(CPointAp pp)
{
	int xpos;

	if (!display_.vert_display && display_.hex_area)
	{
		xpos = char_pos(0) - text_width_w_/2;
		if (pp.x > xpos - 5 && pp.x < xpos + 5)
			return true;
	}
	else if (display_.vert_display || (display_.char_area && !display_.hex_area))
	{
		xpos = char_pos(rowsize_ - 1) + (3*text_width_w_)/2;
		if (pp.x > xpos - 5 && pp.x < xpos + 5)
			return true;
	}
	return false;
}