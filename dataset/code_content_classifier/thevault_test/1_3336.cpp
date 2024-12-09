void CAerialView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if (pHint == NULL)
		return;

	if (pHint->IsKindOf(RUNTIME_CLASS(CHexHint)) ||
		pHint->IsKindOf(RUNTIME_CLASS(CBGSearchHint)) ||
		pHint->IsKindOf(RUNTIME_CLASS(CBookmarkHint)) ||
		pHint->IsKindOf(RUNTIME_CLASS(CBGAerialHint))   )
	{
		// Document, search occurrences, or bookmarks have changed
		get_disp_params(rows_, cols_, actual_dpix_);  // file length may have changed which could change actual_dpix_
		update_display();
		Invalidate();
	}
}