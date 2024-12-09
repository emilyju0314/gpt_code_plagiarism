void CAerialView::SetScroll(int newpos)
{
	CHexEditDoc *pDoc = GetDocument();
	int width = pDoc->GetBpe() * cols_;                 // row width in bytes
	ASSERT(scrollpos_/width < INT_MAX);
	int pos = int(scrollpos_/width);                    // current pos as row no
	ASSERT((pDoc->length()-1)/width + 1 < INT_MAX);
	int endpos = int((pDoc->length()-1)/width + 1);     // row just past eof

	// Make sure new scroll pos is valid
	if (newpos > endpos - rows_)
		newpos = endpos - rows_;
	if (newpos < 0)
		newpos = 0;
	if (newpos == pos)
		return;                                         // no change

	scrollpos_ = FILE_ADDRESS(newpos) * width;
	if (abs(newpos - pos) > rows_/2)
		Invalidate();           // Just redraw it all if scrolling more than half a page
	else
	{
		CRect rct;
		rct.left   = bdr_left_;
		rct.right  = bdr_left_ + cols_ * actual_dpix_;
		rct.top    = bdr_top_;
		rct.bottom = bdr_top_ + rows_ * actual_dpix_;
		ScrollWindow(0, (pos - newpos)*actual_dpix_, rct, rct);
		rct.left   = 0; rct.right = bdr_left_;
		ScrollWindow(0, (pos - newpos)*actual_dpix_, rct, rct);
	}
	update_bars();
	update_display();

	// Make sure we are not displaying a tip for the elt under the mouse as it has just changed
	if (!tip_.FadingOut())   // Don't keep it alive if we have already told it to fade away
		tip_.Hide(300);
}