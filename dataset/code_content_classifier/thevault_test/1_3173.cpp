void CHexEditView::invalidate_adjuster(int col)
{
	if (col < 0)
		return;
	CRect rct(-1, 0, -1, 30000);
	if (!display_.vert_display && display_.hex_area)
	{
		rct.left = hex_pos(col) - scrollpos_.x;
		rct.right = rct.left + 4;
		rct.left -= 7;
		if (col%group_by_ == 0)
			rct.left -= text_width_;
		InvalidateRect(&rct);   // DoInvalidateRect not nec. as we can't be in a macro??
	}
	if (display_.vert_display || display_.char_area)
	{
		rct.left = char_pos(col) - scrollpos_.x;
		rct.right = rct.left + 4;
		rct.left -= 7;
		if (display_.vert_display && col%group_by_ == 0)
			rct.left -= text_width_w_/2;
		InvalidateRect(&rct);
	}
}