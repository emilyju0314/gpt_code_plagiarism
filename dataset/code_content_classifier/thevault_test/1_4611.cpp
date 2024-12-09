BOOL CVSUtils::EnsureRectangleOnDisplay(RECT *prc)
{
	HMONITOR hMonitor;
	MONITORINFO mi;
	memset(&mi, 0, sizeof(mi));
	mi.cbSize = sizeof(mi);

	if (!prc)
		return FALSE;

	hMonitor = MonitorFromRect(prc,	MONITOR_DEFAULTTONEAREST);
	if (hMonitor)
		GetMonitorInfo(hMonitor, &mi);

	// Now we have a clipping rectangle,
	// bring our input rectangle into sight.
	if (prc->right > mi.rcWork.right)
	{
		prc->left -= prc->right - mi.rcWork.right;
		prc->right = mi.rcWork.right;
	}
	if (prc->bottom > mi.rcWork.bottom)
	{
		prc->top -= prc->bottom - mi.rcWork.bottom;
		prc->bottom = mi.rcWork.bottom;
	}
	if (prc->left < mi.rcWork.left)
	{
		prc->right += mi.rcWork.left - prc->left;
		prc->left = mi.rcWork.left;
	}
	if (prc->top < mi.rcWork.top)
	{
		prc->bottom += mi.rcWork.top - prc->top;
		prc->top = mi.rcWork.top;
	}

	return TRUE;
}