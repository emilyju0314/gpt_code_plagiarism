void CHexEditView::add_ruler_tip(CPoint pt, CString ss, COLORREF colour)
{
	// Change appearance
	ruler_tip_.SetWindowText(ss);
	ruler_tip_.SetBgCol(colour);

	// Change location and make sure it's visible
	CPoint tip_pt;
	tip_pt = pt + CSize(text_width_w_, text_height_/2);
	ClientToScreen(&tip_pt);
	ruler_tip_.Move(tip_pt, false);
	ruler_tip_.Show();
}