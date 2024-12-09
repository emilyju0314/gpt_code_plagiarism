void CCompareView::recalc_display()
{
	if (phev_ == NULL) return;

	// Ensure ScrView scrolling matches global options
	if (GetScrollPastEnds() != theApp.scroll_past_ends_)
	{
		SetScrollPastEnds(theApp.scroll_past_ends_);
		SetScroll(GetScroll());
	}
	SetAutoscroll(theApp.autoscroll_accel_);

	// phev_->recalc_display();  // we now assume that the hex view is up to date

	// Make sure our borders are the same as hex view's
	bdr_top_ = phev_->bdr_top_;
	bdr_bottom_ = phev_->bdr_bottom_;
	bdr_left_ = phev_->bdr_left_;
	bdr_right_ = phev_->bdr_right_;

	// Calculate width of address area which may be different than hex view's address width
	calc_addr_width(GetDocument()->CompLength() + phev_->display_.addrbase1);

	if (phev_->display_.vert_display)
		SetTSize(CSizeAp(-1, ((GetDocument()->CompLength() + phev_->offset_)/phev_->rowsize_ + 1)*3));  // 3 rows of text
	else
		SetTSize(CSizeAp(-1, (GetDocument()->CompLength() + phev_->offset_)/phev_->rowsize_ + 1));

	// Make sure we know the width of the display area
	if (phev_->display_.vert_display || phev_->display_.char_area)
		SetSize(CSize(char_pos(phev_->rowsize_-1)+phev_->text_width_w_+phev_->text_width_w_/2+1, -1));
	else
	{
		ASSERT(phev_->display_.hex_area);
		SetSize(CSize(hex_pos(phev_->rowsize_-1)+2*phev_->text_width_+phev_->text_width_/2+1, -1));
	}
}