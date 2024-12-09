void CHexEditView::view_context(CPoint point)
{
#if 0 // Changes for BCG context menus
	// Get the top level menu that contains the submenus used as popup menus
	CMenu top;
	BOOL ok = top.LoadMenu(IDR_CONTEXT);
	ASSERT(ok);
	if (!ok) return;

	CMenu *ppop;
	if (point.x < hex_pos(0))
	{
		// Context menu for address area
		ppop = top.GetSubMenu(1);
	}
	else if (display_.char_area && point.x >= char_pos(0))
	{
		// Context menu for character area
		ppop = top.GetSubMenu(2);
	}
	else
	{
		// Context menu for hex area
		ppop = top.GetSubMenu(3);
	}
	ASSERT(ppop != NULL);
	if (ppop != NULL)
	{
		// Convert window coords to the required screen coords
		ClientToScreen(&point);
		VERIFY(ppop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
									point.x, point.y, GetFrame()));
	}

	top.DestroyMenu();
#else
	CContextMenuManager *pCMM = theApp.GetContextMenuManager();

	CPoint cli_pt(point);              // The point clicked in doc coords
	ScreenToClient(&cli_pt);
	CPointAp doc_pt = ConvertFromDP(cli_pt);

#if 0  // comment this out so we always get some context menu
	if (( (display_.vert_display || display_.char_area) && doc_pt.x >= char_pos(rowsize_)+text_width_ ||
		 !(display_.vert_display || display_.char_area) && doc_pt.x >= hex_pos(rowsize_) )  )
	{
		// Don't do anything if off to right
		return;
	}
#endif

	if (doc_pt.x < hex_pos(0))
		pCMM->ShowPopupMenu(IDR_CONTEXT_ADDRESS, point.x, point.y, this);
	else if (display_.vert_display)
	{
		// Get selection address
		FILE_ADDRESS start_addr, end_addr;
		GetSelAddr(start_addr, end_addr);

		// Get address clicked on in char area
		FILE_ADDRESS addr = (doc_pt.y/line_height_)*rowsize_ - offset_ +
							pos_char(doc_pt.x);

		if (addr >= start_addr && addr < end_addr)
			pCMM->ShowPopupMenu(IDR_CONTEXT_SELECTION, point.x, point.y, this);
		else if (!display_.hide_bookmarks &&
				 std::find(GetDocument()->bm_posn_.begin(), GetDocument()->bm_posn_.end(), addr) != GetDocument()->bm_posn_.end())
			pCMM->ShowPopupMenu(IDR_CONTEXT_BOOKMARKS, point.x, point.y, this);
		else if (!display_.hide_highlight && hl_set_.find(addr) != hl_set_.end())
			pCMM->ShowPopupMenu(IDR_CONTEXT_HIGHLIGHT, point.x, point.y, this);
		else if (pos2row(doc_pt) == 0)
			pCMM->ShowPopupMenu(IDR_CONTEXT_CHAR, point.x, point.y, this);
		else
			pCMM->ShowPopupMenu(IDR_CONTEXT_HEX, point.x, point.y, this);
	}
	else if (!display_.char_area || doc_pt.x < char_pos(0))
	{
		// Get selection address
		FILE_ADDRESS start_addr, end_addr;
		GetSelAddr(start_addr, end_addr);

		// Get address clicked on in hex area
		FILE_ADDRESS addr = (doc_pt.y/text_height_)*rowsize_ - offset_ +
							pos_hex(doc_pt.x);

		if (addr >= start_addr && addr < end_addr)
			pCMM->ShowPopupMenu(IDR_CONTEXT_SELECTION, point.x, point.y, this);
		else if (!display_.hide_bookmarks &&
				 std::find(GetDocument()->bm_posn_.begin(), GetDocument()->bm_posn_.end(), addr) != GetDocument()->bm_posn_.end())
			pCMM->ShowPopupMenu(IDR_CONTEXT_BOOKMARKS, point.x, point.y, this);
		else if (!display_.hide_highlight && hl_set_.find(addr) != hl_set_.end())
			pCMM->ShowPopupMenu(IDR_CONTEXT_HIGHLIGHT, point.x, point.y, this);
		else
			pCMM->ShowPopupMenu(IDR_CONTEXT_HEX, point.x, point.y, this);
	}
	else
	{
		// Get selection address
		FILE_ADDRESS start_addr, end_addr;
		GetSelAddr(start_addr, end_addr);

		// Get address clicked on in char area
		FILE_ADDRESS addr = (doc_pt.y/text_height_)*rowsize_ - offset_ +
							pos_char(doc_pt.x);

		if (addr >= start_addr && addr < end_addr)
			pCMM->ShowPopupMenu(IDR_CONTEXT_SELECTION, point.x, point.y, this);
		else if (!display_.hide_bookmarks &&
				 std::find(GetDocument()->bm_posn_.begin(), GetDocument()->bm_posn_.end(), addr) != GetDocument()->bm_posn_.end())
			pCMM->ShowPopupMenu(IDR_CONTEXT_BOOKMARKS, point.x, point.y, this);
		else if (!display_.hide_highlight && hl_set_.find(addr) != hl_set_.end())
			pCMM->ShowPopupMenu(IDR_CONTEXT_HIGHLIGHT, point.x, point.y, this);
		else
			pCMM->ShowPopupMenu(IDR_CONTEXT_CHAR, point.x, point.y, this);
	}
#endif
}