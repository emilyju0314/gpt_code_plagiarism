void CHexEditView::SaveMove()
{
	undo_.push_back(view_undo(undo_move));
	undo_.back().address = saved_start_ | (FILE_ADDRESS(saved_row_)<<62);
	if (saved_start_ != saved_end_)
	{
		// Save the previous selection
		undo_.push_back(view_undo(undo_sel));
		undo_.back().address = saved_end_;
	}
}