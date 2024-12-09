int CDpiAware::QueryDpiForWindow(HWND hWnd /*= NULL*/, DpiValue* pDpi /*= NULL*/)
{
	#if defined(_DEBUG) && defined(DPI_DEBUG_CUSTOM)
	if (pDpi) pDpi->SetDpi(DPI_DEBUG_CUSTOM,DPI_DEBUG_CUSTOM);
	return DPI_DEBUG_CUSTOM;
	#endif

	int dpi = 96;
	HDC desktopDc = GetDC(hWnd);
	if (desktopDc != NULL)
	{
		// Get native resolution
		int x = GetDeviceCaps(desktopDc, LOGPIXELSX);
		int y = GetDeviceCaps(desktopDc, LOGPIXELSY);
		ReleaseDC(NULL, desktopDc);
		if (x >= 96 && y >= 96)
		{
			if (pDpi)
			{
				pDpi->Xdpi = x; pDpi->Ydpi = y;
			}
			dpi = y;
		}
	}
	return dpi;
}