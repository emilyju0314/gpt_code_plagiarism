void CExplorerWnd::update_types()
{
	SHCONTF flags = SHCONTF_FOLDERS;

	if (show_hidden > 0)
		flags |= SHCONTF_INCLUDEHIDDEN;

#if _MFC_VER >= 0x0A00
	// Note that the SHCONTF_INCLUDESUPERHIDDEN option has no effect if the Windows Explorer option
	// "Hide protected (operating system) files (Recommended)" is off since HIDDEN files are already shown
	if (theApp.is_win7_ && show_hidden > 1)
		flags |= SHCONTF_INCLUDESUPERHIDDEN;
#endif

	tree_.SetFlags(flags);
	list_.SetItemTypes(flags | SHCONTF_NONFOLDERS);
}