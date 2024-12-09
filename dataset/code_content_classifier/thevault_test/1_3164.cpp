void CHexEditView::DoInvalidateRect(LPCRECT lpRect)
{
	if (((CHexEditApp *)AfxGetApp())->refresh_off_)
		needs_refresh_ = true;
	else
		CScrView::DoInvalidateRect(lpRect);
}