int CHexEditView::pos_hex(int pos, int inside) const
{
	int col = pos - addr_width_*text_width_;
	col -= (col/(text_width_*(group_by_*3+1)))*text_width_;
	col = col/(3*text_width_);

	// Make sure col is within valid range
	if (col < 0) col = 0;
	else if (inside == 1 && col >= rowsize_) col = rowsize_ - 1;
	else if (inside == 0 && col > rowsize_) col = rowsize_;

	return col;
}