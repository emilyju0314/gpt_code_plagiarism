HRESULT CHistoryShellList::DisplayFolder(LPAFX_SHELLITEMINFO lpItemInfo)
{
	if (pExpl_ != NULL)
	{
		// Don't sync the very first time (startup) since this can really slow down the
		// startup time (especailly if there are missing network drives).
		static bool first = true;
		if (first)
			first = false;
		else if (theApp.sync_tree_)
			pExpl_->LinkToTree();    			// We should have already called tree_.SetRelatedList()
	}

	HRESULT retval = CMFCShellListCtrl::DisplayFolder(lpItemInfo);

	if (retval == S_OK && pExpl_ != NULL && !in_move_)
	{
		CString curr;
		if (GetCurrentFolder(curr) &&
			(pos_ == -1 || curr.CompareNoCase(name_[pos_]) != 0) )
		{
			// Truncate the list past the current pos
			ASSERT(pos_ >= -1 && pos_ < int(name_.size()));
			name_.erase(name_.begin() + (pos_ + 1), name_.end());
			pos_ = name_.size();

			name_.push_back(curr);
			if (add_to_hist_)
				pExpl_->AddFolder();
		}
		pExpl_->UpdateFolderInfo(curr);
	}

	return retval;
}