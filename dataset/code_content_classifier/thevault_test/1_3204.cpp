CHexEditView * CHexEditView::PrevView() const
{
	CChildFrame *currc = dynamic_cast<CChildFrame *>(GetFrame());
	ASSERT(currc != NULL);
	CChildFrame *prevc = currc;

	do
	{
		// Get next sibling window (which are the child frames of other views)
		CWnd * pw = prevc->GetWindow(GW_HWNDNEXT);

		// If reached the end of the list go back around
		if (pw == NULL)
			pw = prevc->GetWindow(GW_HWNDFIRST);

		// Skip any windows that are not child frames (eg MFC 10 has added a CMFCTabCtrl window at this level)
		while (!pw->IsKindOf(RUNTIME_CLASS(CChildFrame)))
		{
			pw = pw->GetWindow(GW_HWNDNEXT);
			if (pw == NULL)
				pw = prevc->GetWindow(GW_HWNDFIRST);
		}

		// Get the window as a child frame
		prevc = dynamic_cast<CChildFrame *>(pw);
	} while (prevc != NULL && prevc != currc && prevc->IsIconic());

	if (prevc == NULL || prevc == currc)
		return NULL;
	else
		return prevc->GetHexEditView();
}