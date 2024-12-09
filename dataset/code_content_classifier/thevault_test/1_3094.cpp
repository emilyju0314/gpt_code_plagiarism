void CHexEditView::draw_group_by(CDC* pDC, int xpos)
{
	pDC->BeginPath();
	pDC->MoveTo(xpos - 3, bdr_top_ - 7);
	pDC->LineTo(xpos - 3, bdr_top_ - 5);
	pDC->LineTo(xpos,     bdr_top_ - 2);
	pDC->LineTo(xpos + 3, bdr_top_ - 5);
	pDC->LineTo(xpos + 3, bdr_top_ - 7);
	pDC->EndPath();
	pDC->StrokeAndFillPath();
}