void CHexEditView::move_dlgs()
{
	// Get doc size so we know width of visible area
	CSizeAp tt, pp, ll;                 // Size of document total,page,line
	GetSize(tt, pp, ll);

	// Get the selection so we can work out a rectangle bounding the selection
	CPointAp start, end;                // Points of start/end of selection
	GetSel(start, end);

	CRectAp selrect;                    // Rect enclosing selection + a bit
	if (start.y == end.y)               // No selection or all on a single line?
		selrect = CRectAp(start.x - 2*ll.cx, start.y - ll.cy,
						  end.x + 3*ll.cx, end.y + 2*ll.cy);
	else
		selrect = CRectAp(0, start.y - ll.cy,  // multi-line selection
						  tt.cx, end.y + 2*ll.cy);

	// Get display rectangle (also in doc coords)
	CRect cli;
	GetDisplayRect(&cli);
	CRectAp doc_rect = ConvertFromDP(cli);

	// See if any of the selection is visible (intersect selection & display)
	CRectAp sd_rect;                    // selection that is visible
	if (!sd_rect.IntersectRect(doc_rect, selrect))
		return;                         // Selection not in display

	// Get rect (selection visible in display) in screen (device) coords
	CRect dev_rect = ConvertToDP(sd_rect);
	ClientToScreen(&dev_rect);

	HideCaret();
	// Tell mainframe to move all its dialog bars
	if (theApp.dlg_move_)
		((CMainFrame *)theApp.m_pMainWnd)->move_bars(dev_rect);
	ShowCaret();
}