CChildFrame *CHexEditView::comp_window()
{
	CMainFrame *mm = dynamic_cast<CMainFrame *>(AfxGetMainWnd());
	CChildFrame *nextc;         // Loops through all MDI child frames
	CChildFrame *compc = NULL;  // Frame of view available to compare with
	BOOL got_one;               // Have we gound an appropriate view?

	// Get the currently active child MDI window
	nextc = dynamic_cast<CChildFrame *>(mm->MDIGetActive());
	ASSERT(nextc != NULL);
	ASSERT(nextc->GetHexEditView() == this);

	// Search for another (non-iconized) window
	for (got_one = FALSE, nextc = dynamic_cast<CChildFrame *>(nextc->GetWindow(GW_HWNDNEXT));
		 nextc != NULL; nextc = dynamic_cast<CChildFrame *>(nextc->GetWindow(GW_HWNDNEXT)) )
	{
		if (!nextc->IsIconic())
		{
			// More than one found - use which one?
			if (got_one)
			{
// Can't display message when used in OnUpdateEditCompare call
//              AfxMessageBox("Comparison not performed\n"
//                              "- more than two (non-iconized) windows");
				return NULL;
			}
			got_one = TRUE;
			compc = nextc;
		}
	}

	// If we didn't find a non-iconized window search for iconized one
	if (compc == NULL)
	{
		nextc = dynamic_cast<CChildFrame *>(mm->MDIGetActive());

		// Search for an iconized window
		for (got_one = FALSE, nextc = dynamic_cast<CChildFrame *>(nextc->GetWindow(GW_HWNDNEXT));
			 nextc != NULL; nextc = dynamic_cast<CChildFrame *>(nextc->GetWindow(GW_HWNDNEXT)) )
		{
			ASSERT(nextc->IsIconic());          // else compc != NULL
			// If more than one window - use which one?
			if (got_one)
			{
// Can't display message when used in OnUpdateEditCompare call
//              AfxMessageBox("Comparison not performed\n"
//                              "- more than two windows found");
				return NULL;
			}
			got_one = TRUE;
			compc = nextc;
		}
	}
	return compc;
}