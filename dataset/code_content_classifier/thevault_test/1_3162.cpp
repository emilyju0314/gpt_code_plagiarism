void CHexEditView::SetCodePage(int cp)
{
	if (cp == code_page_)    // same as current
		return;

	code_page_ = cp;
	if (code_page_ == CP_UTF8)
	{
		max_cp_bytes_ = 0;  // UTF-8 is handled differently - set to zero to detect accidental use of normal CP code
		return;
	}

	CPINFOEX cpie;
	VERIFY(GetCPInfoEx(code_page_, 0, &cpie));
	max_cp_bytes_ = cpie.MaxCharSize;
}