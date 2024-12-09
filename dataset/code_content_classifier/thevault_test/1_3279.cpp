void CHistoryShellList::do_move(int ii)
{
	// Detect problems but handle them in release too (defensive programming)
	ASSERT(ii >= 0 && ii < int(name_.size()));
	if (ii < 0)
		ii = 0;
	else if (ii >= int(name_.size()))
		ii = name_.size() - 1;

	// Now move to the folder
	in_move_ = true;
	CMFCShellListCtrl::DisplayFolder(name_[ii]);
	in_move_ = false;

	ASSERT(pExpl_ != NULL);
	pExpl_->UpdateFolderInfo(name_[ii]);

	pos_ = ii;
}