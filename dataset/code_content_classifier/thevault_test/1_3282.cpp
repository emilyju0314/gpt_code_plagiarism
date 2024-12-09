DROPEFFECT CExplorerDropTarget::DragCheck (COleDataObject* pDataObject,
						DWORD dwKeyState, CPoint point )
{
	DROPEFFECT retval = DROPEFFECT_MOVE;

	// Get the destination folder of the move and the folders/files to move
	CString dst = GetDst(point);
	if (dst.IsEmpty())
		return DROPEFFECT_NONE;       // Current drag folder is not a drop target
	std::vector<CString> src;
	GetNames(pDataObject, src);

	for (std::vector<CString>::const_iterator psrc = src.begin(); psrc != src.end(); ++psrc)
	{
		DROPEFFECT de;
		if (::PathIsDirectory(*psrc))
			de = CanMoveFolder(*psrc, dst);
		else
			de = CanMove(*psrc, dst);

		if (de == DROPEFFECT_NONE)
		{
			retval = DROPEFFECT_NONE;      // if we can't drag any then return NONE
			break;
		}
		else if (de == DROPEFFECT_COPY)
			retval = DROPEFFECT_COPY;     // if we can't move any then return COPY
	}
	if (retval == DROPEFFECT_MOVE && (dwKeyState & MK_CONTROL) != 0)
		retval = DROPEFFECT_COPY;
	if (retval == DROPEFFECT_COPY && (dwKeyState & MK_SHIFT) != 0)
		retval = DROPEFFECT_MOVE;
	return retval;
}