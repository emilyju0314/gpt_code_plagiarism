void CNavManager::AddItems(CMFCPopupMenu* pMenuPopup, bool forward, UINT first, int max_items)
{
	ASSERT( forward || pos_ /* + pos_offset() */ >= 0);        // Can only show backward pts if there are any
	ASSERT(!forward || pos_ < int(v_.size()) - 1);          // Can only show forward pts if there are any

	// Create a sub-menu for each window here.  Note that this items appear on time order
	// so the same window may appear more than once in the lists (but not consecutively).
	CMenu *submenu = NULL;
	int menu_items = 0;           // Items added so far to current sub-menu

	CHexEditView *pview = NULL;   // Previous view
	CHexEditDoc *pdoc = NULL;     // Previous doc
	CString pname;                // Previous file name

	for (int ii = 0, curr = (forward ? pos_ + 1 : pos_ /* + pos_offset() */);
		 ii < max_items && ((forward && curr < int(v_.size())) || (!forward && curr >= 0));
		 ++ii, (forward ? ++curr : curr--) )
	{
		// Check if we need to start a new sub-menu
		if (v_[curr].pview_ != pview)
		{
			// save current submenu and start a new one
			if (submenu != NULL)
			{
				CString ss;

				ASSERT(pview != NULL && pdoc != NULL);
				if (is_open_view(pdoc, pview))
					pview->GetFrame()->GetWindowText(ss);
				else if (!pname.IsEmpty())
					ss = pname;
				else
					ss = "Closed file";         // Closed without saving to disk?
				pMenuPopup->InsertItem(CMFCToolBarMenuButton(-1, submenu->GetSafeHmenu(), -1, ss));
				delete submenu;
				submenu = NULL;
			}

			submenu = new CMenu;
			submenu->CreatePopupMenu();
			pview = v_[curr].pview_;
			pdoc = v_[curr].pdoc_;
			pname = v_[curr].fname_;
			menu_items = 0;                     // Starting new sub-menu
		}

		// Only add max 50 items per sub-menu
		if (menu_items < 50)
		{
			UINT flags = MF_ENABLED;
			if (!forward && ii == 0 && pos_offset() == -1)
				flags |= MF_CHECKED;

#if 0  // Can we make this work???
			// Note: We tried saving nav point in menu item data rather than adding index to "first" to
			// get the menu item ID (command ID) to save IDs but by the time the command is received (see
			// CMainFrame::OnNavBack/Forw) the menu is already gone.
			// Check if we have run out of items (reserved command IDs)
			if (total_items >= max_items)
				break;                     // out of command ids
			submenu->AppendMenu(flags, first + total_items, v_[curr].desc_);

			// Save nav point index in menu item data so we know which nav pt is selected by the menu item
			MENUITEMINFO mii;
			memset(&mii, '\0', sizeof(mii));
			mii.cbSize = sizeof(mii);
			mii.fMask = MIIM_DATA;
			mii.dwItemData = ii;
			submenu->SetMenuItemInfo(first + total_items, &mii);
			++total_items;
#else
			submenu->AppendMenu(flags, first + ii, v_[curr].desc_);
#endif
			++menu_items;                       // Track how many items are in this sub-menu
		}
	}
	ASSERT(submenu != NULL && pview != NULL);   // This should not be NULL since there must be at least one item
	if (submenu != NULL)
	{
		CString ss;
		if (is_open_view(pdoc, pview))
			pview->GetFrame()->GetWindowText(ss);
		else if (!pname.IsEmpty())
			ss = pname;
		else
			ss = "Closed file";
		pMenuPopup->InsertItem(CMFCToolBarMenuButton(-1, submenu->GetSafeHmenu(), -1, ss));
		delete submenu;
		submenu = NULL;
	}
}