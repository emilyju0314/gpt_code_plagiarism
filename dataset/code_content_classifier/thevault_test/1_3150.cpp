void CHexEditView::OnSelScheme()
{
	CMFCToolBarComboBoxButton * ptbcbb = NULL;

	// Get and search all ID_SCHEME toolbar controls (there may be more than one on different toolbars)
	CObList listButtons;
	if (CMFCToolBar::GetCommandButtons(::IsUs() ? ID_SCHEME_US : ID_SCHEME, listButtons) > 0)
	{
		for (POSITION posCombo = listButtons.GetHeadPosition();
			 posCombo != NULL;)
		{
			CMFCToolBarComboBoxButton* pp = DYNAMIC_DOWNCAST(CMFCToolBarComboBoxButton, listButtons.GetNext(posCombo));

			if (pp != NULL && CMFCToolBar::IsLastCommandFromButton(pp))  // check that this one actually was the one used
			{
				ptbcbb = pp;
				break;
			}
		}
	}

	if (ptbcbb != NULL)
	{
		ASSERT_VALID(ptbcbb);

		CString name = CString(ptbcbb->GetItem());  // GetItem(-1) will return the selected one
		if (name.Right(3) == "...")
			theApp.display_options(COLOUR_OPTIONS_PAGE, TRUE);
		else if (!name.IsEmpty() && name[0] != '-')
			SetScheme(name);
	}
}