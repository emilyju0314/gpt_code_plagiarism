void CCompareView::begin_change()
{
	previous_caret_displayed_ = CaretDisplayed();
	previous_end_base_ = GetSelAddr(previous_start_addr_, previous_end_addr_);
	previous_row_ = 0;
	if (previous_start_addr_ == previous_end_addr_ && phev_->display_.vert_display)
		previous_row_ = pos2row(GetCaret());
}