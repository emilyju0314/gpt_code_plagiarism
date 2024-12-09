int CHexEditView::pos_char(int pos, int inside) const
{
	int col;
	if (display_.vert_display)
	{
		col = (pos - addr_width_*text_width_)/text_width_w_;
		col -= col/(group_by_+1);
	}
	else if (display_.hex_area)
		col = (pos - addr_width_*text_width_ -
			   rowsize_*3*text_width_ - ((rowsize_-1)/group_by_)*text_width_) / text_width_w_;
	else
		col = (pos - addr_width_*text_width_) / text_width_w_;

	// Make sure col is within valid range
	if (col < 0) col = 0;
	else if (inside == 1 && col >= rowsize_) col = rowsize_ - 1;
	else if (inside == 0 && col > rowsize_) col = rowsize_;

	return col;
}