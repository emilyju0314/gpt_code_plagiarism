int CCompareView::pos_hex(int pos, int inside) const
{
	int col = pos - addr_width_*phev_->text_width_;
	col -= (col/(phev_->text_width_*(phev_->group_by_*3+1)))*phev_->text_width_;
	col = col/(3*phev_->text_width_);

	// Make sure col is within valid range
	if (col < 0) col = 0;
	else if (inside == 1 && col >= phev_->rowsize_) col = phev_->rowsize_ - 1;
	else if (inside == 0 && col > phev_->rowsize_) col = phev_->rowsize_;

	return col;
}