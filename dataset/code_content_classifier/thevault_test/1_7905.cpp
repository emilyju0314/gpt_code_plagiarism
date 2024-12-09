void CevolveView::OnClearDye()
{
	CevolveApp *app = (CevolveApp *) AfxGetApp();
	CevolveDoc *pDoc = GetDocument();
	UNIVERSE *u = pDoc->universe;

	app->DoWaitCursor(1);

	Universe_ClearTracers(u);

	app->DoWaitCursor(-1);
	pDoc->SetModifiedFlag(true);
	Invalidate(true);

}