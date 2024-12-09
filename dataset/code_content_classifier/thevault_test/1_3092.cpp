void CHexEditView::draw_rowsize(CDC* pDC, int xpos)
{
	pDC->BeginPath();
	pDC->MoveTo(xpos + 2, bdr_top_ - 7);
	pDC->LineTo(xpos,     bdr_top_ - 7);
	pDC->LineTo(xpos - 3, bdr_top_ - 4);
	pDC->LineTo(xpos,     bdr_top_ - 1);
	pDC->LineTo(xpos + 2, bdr_top_ - 1);
	pDC->EndPath();
	pDC->StrokeAndFillPath();
}