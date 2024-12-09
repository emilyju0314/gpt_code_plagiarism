void CPrevwView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if (pHint == NULL)
		return;

	if (pHint->IsKindOf(RUNTIME_CLASS(CBGPreviewHint)))
	{
		validate_display();
		Invalidate();
		phev_->show_prop();
	}
}