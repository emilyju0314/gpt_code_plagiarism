void CAerialView::draw_left_border(CDC* pDC, int left, int right, int row, COLORREF clr)
{
	ASSERT(left < right && right <= bdr_left_);
	for (int rr = 0; rr < actual_dpix_; ++rr)
		for (int cc = left; cc < right; ++cc)
			pDC->SetPixel(cc, bdr_top_ + row*actual_dpix_ + rr, clr);
}