static void Draw3DFrame(CDC *pDC, CRect rcBox, COLORREF colBottomRight, COLORREF colTopLeft)
{
	CPen *pPen2, *pPen, *pOldPen;

	pPen = new CPen(PS_SOLID, 1, colBottomRight);
	pOldPen = pDC->SelectObject(pPen);
	pDC->MoveTo(rcBox.right-1, rcBox.top);
	pDC->LineTo(rcBox.right-1, rcBox.bottom-1);
	pDC->LineTo(rcBox.left-1, rcBox.bottom-1);

	pPen2 = new CPen(PS_SOLID, 1, colTopLeft);
	pDC->SelectObject(pPen2);
	delete pPen;

	pDC->MoveTo(rcBox.left, rcBox.bottom-2);
	pDC->LineTo(rcBox.left, rcBox.top);
	pDC->LineTo(rcBox.right-1, rcBox.top);

	pDC->SelectObject(pOldPen);
	delete pPen2;
}