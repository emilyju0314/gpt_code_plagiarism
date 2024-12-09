BOOL CHexEditView::make_change(BOOL ptoo /*=FALSE*/)
{
	if (previous_state_ != disp_state_)
	{
		if (theApp.intelligent_undo_ &&         // intelligent undo is turned on
			undo_.size() > 0 &&                 // there is an undo op on the stack
			undo_.back().utype == undo_state && // previous op was a state change
			!undo_.back().previous_too &&       // and not part of another operation
			undo_.back().disp_state == disp_state_) // and same state
		{
			ASSERT(!ptoo);     // if part of larger op then previous utype should not have been undo_state
			undo_.pop_back();
		}
		else
		{
			undo_.push_back(view_undo(undo_state, ptoo));
			undo_.back().disp_state = previous_state_;
			ptoo = TRUE;
		}
	}

	return ptoo;
}