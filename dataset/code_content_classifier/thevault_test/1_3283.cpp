DROPEFFECT CExplorerDropTarget::CanMove(LPCTSTR file, LPCTSTR dst)
{
	TCHAR folder[MAX_PATH];
	_tcsncpy(folder, file, MAX_PATH);
	LPTSTR pfn = ::PathFindFileName(folder);
	pfn--;
	ASSERT(pfn > folder && pfn < folder + MAX_PATH);        // Make sure it points into the buffer
	ASSERT(*pfn == '\\');
	*pfn = '\0';                                            // Truncate at file name to get folder
	ASSERT(::PathIsDirectory(folder) && ::PathIsDirectory(dst));
	if (::StrCmpI(folder, dst) == 0)
		return DROPEFFECT_NONE;
	else if (::PathIsSameRoot(folder, dst))
		return DROPEFFECT_MOVE;
	else
		return DROPEFFECT_COPY;
}