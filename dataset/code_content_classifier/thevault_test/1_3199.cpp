void CHexEditView::do_autofit(int state /*=-1*/)
{
	CHexEditApp *aa = dynamic_cast<CHexEditApp *>(AfxGetApp());
	CMainFrame *mm = (CMainFrame *)AfxGetMainWnd();

	if (pcv_ != NULL)
		pcv_->begin_change();

//    if (!aa->playing_ && GetFocus() != this) SetFocus(); // Ensure focus does not stay in DlgBar
	num_entered_ = num_del_ = num_bs_ = 0;      // Stop any editing

	BOOL caret_displayed = CaretDisplayed();
	FILE_ADDRESS scroll_addr = pos2addr(GetScroll());

//    FILE_ADDRESS address = pos2addr(GetCaret());
	FILE_ADDRESS start_addr, end_addr;
	BOOL end_base = GetSelAddr(start_addr, end_addr);
	int row = 0;
	if (start_addr == end_addr && display_.vert_display)
		row = pos2row(GetCaret());

	if (state == -1)
		display_.autofit = !display_.autofit;
	else if ((BOOL)state == display_.autofit)
		return;                                 // No change - do nothing
	else
		display_.autofit = (BOOL)state;
	undo_.push_back(view_undo(undo_autofit));
	if (display_.autofit)
		undo_.back().rowsize = rowsize_;
	else
		undo_.back().rowsize = 0;
	recalc_display();
	// Fix scroll place so it's about the same even though the row length has changed
	CPointAp pt = addr2pos(scroll_addr);
	pt.x = 0;
	SetScroll(pt);
	if (end_base)
		SetSel(addr2pos(end_addr, row), addr2pos(start_addr, row), true);
	else
		SetSel(addr2pos(start_addr, row), addr2pos(end_addr, row));
	if (caret_displayed)
		DisplayCaret(); // Keep caret within display
	if (pcv_ != NULL)
		pcv_->end_change();

	DoInvalidate();

	aa->SaveToMacro(km_autofit, state);
}