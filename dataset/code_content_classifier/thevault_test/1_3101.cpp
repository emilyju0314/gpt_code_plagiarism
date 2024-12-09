void CFindSheet::ShowPage(int page)
{
	if (page < 0)
		SetActivePage(p_page_replace_);
	else
		SetActivePage(page);

	theApp.SaveToMacro(km_find_dlg, page);
}