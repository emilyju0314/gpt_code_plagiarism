void CHexEditDoc::OnDffdNew()
{
	OpenDataFormatFile("default");
	ScanFile();
	CDFFDHint dffdh;
	UpdateAllViews(NULL, 0, &dffdh);

	CHexEditView *pv = GetBestView();
	if (pv != NULL)
		pv->ShowDffd();
}