void CAerialView::draw_top_border(CDC* pDC, int col1, int col2, COLORREF clr)
{
	int nrows = bdr_top_;
	if ((col2 - col1)*actual_dpix_ > 2)
		nrows--;             // don't make it too big
	ASSERT(nrows <= bdr_top_);
	for (int rr = 0; rr < nrows; ++rr)
		for (int cc = col1*actual_dpix_; cc < col2*actual_dpix_; ++cc)
			pDC->SetPixel(bdr_left_ + cc, rr, clr);
}