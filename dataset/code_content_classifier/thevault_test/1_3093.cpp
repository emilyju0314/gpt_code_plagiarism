void CHexEditView::draw_offset(CDC* pDC, int xpos)
{
	pDC->BeginPath();
	pDC->MoveTo(xpos - 1, bdr_top_ - 6);
	pDC->LineTo(xpos - 1, bdr_top_ - 2);
	pDC->LineTo(xpos,     bdr_top_ - 1);
	pDC->LineTo(xpos + 3, bdr_top_ - 4);
	pDC->LineTo(xpos,     bdr_top_ - 7);
	pDC->EndPath();
	pDC->StrokeAndFillPath();
}