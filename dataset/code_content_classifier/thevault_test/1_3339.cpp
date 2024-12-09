void CAerialView::update_bars()
{
	SCROLLINFO si;
	memset(&si, 0, sizeof(si)); // default to hiding the scrollbar
	si.cbSize = sizeof(si);
	si.fMask = SIF_ALL;

	CHexEditDoc *pDoc = GetDocument();
	int width = pDoc->GetBpe() * cols_;
	int pos = int(scrollpos_/width);                    // current pos as row no
	int endpos = int((pDoc->length()-1)/width + 1);     // row just past eof

	if (endpos > rows_)                                 // EOF past end of display
	{
		si.nMax = endpos/sbfact_;
		si.nPage = rows_/sbfact_;
		si.nPos = pos/sbfact_;
	}

	SetScrollInfo(SB_VERT, &si);
}