CHexEditView * CHexEditView::NextView() const
{
	CChildFrame *currc = dynamic_cast<CChildFrame *>(GetFrame());
	ASSERT(currc != NULL);
	CChildFrame *nextc = currc;

	do
	{
		// Get previous sibling window (which are the child frames of other views)
		CWnd * pw = nextc->GetWindow(GW_HWNDPREV);

		// If reached the top of the list go to the end
		if (pw == NULL)
			pw = nextc->GetWindow(GW_HWNDLAST);

		// Skip any windows that are not child frames (eg MFC 10 has added a CMFCTabCtrl window at this level)
		while (!pw->IsKindOf(RUNTIME_CLASS(CChildFrame)))
		{
			pw = pw->GetWindow(GW_HWNDPREV);
			if (pw == NULL)
				pw = nextc->GetWindow(GW_HWNDLAST);
		}

		// Get the window as a child frame
		nextc = dynamic_cast<CChildFrame *>(pw);
	} while (nextc != NULL && nextc != currc && nextc->IsIconic());

	if (nextc == NULL || nextc == currc)
		return NULL;
	else
		return nextc->GetHexEditView();
}