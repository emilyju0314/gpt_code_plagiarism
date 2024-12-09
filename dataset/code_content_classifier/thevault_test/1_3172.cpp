void CHexEditView::invalidate_ruler(FILE_ADDRESS addr)
{
	if (!theApp.ruler_)
		return;

	int horz = bdr_left_ - GetScroll().x;       // Offset of left side of doc from left side of window

	CRect rct;
	rct.top = 0;
	rct.bottom = bdr_top_;
	if (!display_.vert_display && display_.hex_area)
	{
		rct.left  = hex_pos(int((addr+offset_)%rowsize_)) + horz;
		rct.right = hex_pos(int((addr+offset_)%rowsize_)+1) + horz;
		DoInvalidateRect(&rct);
	}
	if (display_.vert_display || display_.char_area)
	{
		rct.left  = char_pos(int((addr+offset_)%rowsize_)) + horz;
		rct.right = char_pos(int((addr+offset_)%rowsize_)+1) + horz + 1;
		DoInvalidateRect(&rct);
	}
}