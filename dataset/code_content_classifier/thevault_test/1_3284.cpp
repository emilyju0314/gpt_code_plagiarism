DROPEFFECT CExplorerDropTarget::CanMoveFolder(LPCTSTR folder, LPCTSTR dst)
{
	DROPEFFECT retval = CanMove(folder, dst);
	if (retval != DROPEFFECT_NONE)
	{
		// Also make sure that we don't move a folder to itself or a descendant
		TCHAR common[MAX_PATH];
		size_t len = ::PathCommonPrefix(folder, dst, common);
		if (len == _tcslen(folder))
			retval = DROPEFFECT_NONE;
	}
	return retval;
}