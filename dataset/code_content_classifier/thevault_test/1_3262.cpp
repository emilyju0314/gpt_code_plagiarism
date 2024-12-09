double CPrevwView::zoom_fit()
{
	CHexEditDoc *pDoc = GetDocument();
	ASSERT(pDoc != NULL);

	// Get size of the display area (client area of the window)
	CRect rct;
	GetClientRect(&rct);

	// Get dimensions of the bitmap (as double so we can calculate zoom)
	double bmwidth  = pDoc->preview_width_;
	double bmheight = pDoc->preview_height_;

	return max(bmwidth/rct.Width(), bmheight/rct.Height());
}