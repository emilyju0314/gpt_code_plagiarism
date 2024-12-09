void CHexEditView::invalidate_addr(FILE_ADDRESS addr)
{
	CRect rct;
	GetDisplayRect(&rct);
	CRectAp doc_rect = ConvertFromDP(rct);
	CRect addr_rect;
	addr_rect.left  = bdr_left_;
	addr_rect.right = bdr_left_ - doc_rect.left + addr_width_*text_width_ - text_width_/2;

	// If moved and the address area is visible ...
	if (addr_rect.right <= addr_rect.left)
		return;         // Address area is off window to the left

	FILE_ADDRESS first_disp = (doc_rect.top/line_height_) * rowsize_ - offset_;
	FILE_ADDRESS last_disp = (doc_rect.bottom/line_height_ + 1) * rowsize_ - offset_;
	if (addr >= first_disp && addr < last_disp)
	{
		addr_rect.top    = int(bdr_top_ - doc_rect.top + addr2pos(addr).y);
		addr_rect.bottom = addr_rect.top + text_height_;
		DoInvalidateRect(&addr_rect);
	}
}