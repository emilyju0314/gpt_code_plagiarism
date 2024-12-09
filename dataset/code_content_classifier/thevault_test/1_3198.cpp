BOOL CHexEditView::is_last_change()
{
#ifdef _DEBUG
	{
		// Why can't the debugger look into STL containers?
		int undo_size = undo_.size();
		for (std::vector<view_undo>::reverse_iterator rr = undo_.rbegin(); rr != undo_.rend(); ++rr)
		{
			view_undo undo_elt = *rr;
		}
	}
#endif

	// Check if the last thing on undo stack is a change
	for (std::vector<view_undo>::reverse_iterator pp = undo_.rbegin(); pp != undo_.rend(); ++pp)
	{
		if (pp->utype == undo_change)
			return TRUE;         // Top undo op is a change

		if (!pp->previous_too)
			break;               // End of top undo operation
	}
	return FALSE;
}