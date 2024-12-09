void CHexEditView::OnUpdateScheme(CCmdUI* pCmdUI)
{
	// First check that it is a scheme combo box
	if (pCmdUI->m_pOther != NULL && pCmdUI->m_pOther->GetDlgCtrlID() == (::IsUs() ? ID_SCHEME_US : ID_SCHEME))
	{
		// Find the owning CMFCToolBarComboBoxButton of the combo box
		CMFCToolBarComboBoxButton * ptbcbb = NULL;

		CObList listButtons;
		if (CMFCToolBar::GetCommandButtons(::IsUs() ? ID_SCHEME_US : ID_SCHEME, listButtons) > 0)
		{
			for (POSITION posCombo = listButtons.GetHeadPosition();
				 posCombo != NULL;)
			{
				CMFCToolBarComboBoxButton* pp = DYNAMIC_DOWNCAST(CMFCToolBarComboBoxButton, listButtons.GetNext(posCombo));
				ASSERT(pp != NULL && pp->GetComboBox() != NULL);

				if (pp != NULL && pp->GetComboBox() != NULL && pp->GetComboBox()->m_hWnd == pCmdUI->m_pOther->m_hWnd)
				{
					ptbcbb = pp;
					break;
				}
			}
		}

		// If we found it and it's not in a dropped state
		if (ptbcbb != NULL && !ptbcbb->GetComboBox()->GetDroppedState())
		{
			CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();

			// Work out the current scheme of the active view and get vector of scheme names
			std::vector<CString> scheme_names;
			int current_scheme = -1;

			// Build list backwards as ComboNeedsUpdate() assumes top of list is at bottom of vector
			scheme_names.push_back(CString(::IsUs() ? "Modify Colors..." : "Modify Colours..."));
			scheme_names.push_back(CString('-', 50));  // Add a divider line above the "Modify Colours" line
			for (int ii = theApp.scheme_.size(); ii > 0; ii--)
			{
				scheme_names.push_back(theApp.scheme_[ii-1].name_);
				if (theApp.scheme_[ii-1].name_ == GetSchemeName())
					current_scheme = ii - 1;
			}

			// Make sure the list of schemes in the combo matches the current schemes
			if (mm->ComboNeedsUpdate(scheme_names, ptbcbb->GetComboBox()))
			{
				int max_str = 0;                // Max width of all the strings added so far
				CClientDC dc(ptbcbb->GetComboBox());
				int nSave = dc.SaveDC();
				dc.SelectObject(ptbcbb->GetComboBox()->GetFont());

				ptbcbb->RemoveAllItems();
				for (std::vector<CString>::reverse_iterator ps = scheme_names.rbegin();
					 ps != scheme_names.rend(); ++ps)
				{
					if ((*ps)[0] != '-')
						max_str = __max(max_str, dc.GetTextExtent(*ps).cx);

					// Add the string to the list
					ptbcbb->AddItem(*ps);
				}
				// Add space for margin and possible scrollbar
				//max_str += dc.GetTextExtent("0").cx + ::GetSystemMetrics(SM_CXVSCROLL);
				max_str += ::GetSystemMetrics(SM_CXVSCROLL);
				ptbcbb->GetComboBox()->SetDroppedWidth(__min(max_str, 640));

				dc.RestoreDC(nSave);
			}

			// Make sure the selected scheme in the combo matches the scheme in use in this view
			if (ptbcbb->GetCurSel() != current_scheme)
			{
				ptbcbb->SelectItem(current_scheme);

				// We need to invalidate the button so it show the correct scheme
				CMFCToolBar *ptb = DYNAMIC_DOWNCAST(CMFCToolBar, ptbcbb->GetComboBox()->GetParent());
				int idx = ptb->CommandToIndex(::IsUs() ? ID_SCHEME_US : ID_SCHEME);
				ptb->InvalidateButton(idx);
			}

		}
	}
}