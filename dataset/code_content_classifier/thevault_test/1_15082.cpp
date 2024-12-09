void DrawEditorInfoBox(const ST::string& str, SGPFont const font, UINT16 x, UINT16 y, UINT16 w, UINT16 h)
{
	UINT16 usFillColorDark, usFillColorLight, usFillColorBack;
	UINT16 x2, y2;

	y  += TASKBAR_Y;
	x2  = x + w;
	y2  = y + h;

	usFillColorDark = Get16BPPColor(FROMRGB(24, 61, 81));
	usFillColorLight = Get16BPPColor(FROMRGB(136, 138, 135));
	usFillColorBack = Get16BPPColor(FROMRGB(250, 240, 188));

	ColorFillVideoSurfaceArea(ButtonDestBuffer, x, y, x2, y2, usFillColorDark);
	ColorFillVideoSurfaceArea(ButtonDestBuffer, x + 1, y + 1, x2, y2, usFillColorLight);
	ColorFillVideoSurfaceArea(ButtonDestBuffer, x + 1, y + 1, x2 - 1, y2 - 1, usFillColorBack);

	UINT16 const usStrWidth = StringPixLength(str, font);
	if( usStrWidth > w )
	{ //the string is too long, so use the wrapped method
		y += 1;
		DisplayWrappedString(x, y, w, 2, font, FONT_BLACK, str, FONT_BLACK, CENTER_JUSTIFIED | MARK_DIRTY);
		return;
	}
	//center the string vertically and horizontally.
	SetFontAttributes(font, FONT_BLACK, NO_SHADOW);
	x += (w - StringPixLength(str, font)) / 2;
	y += (h - GetFontHeight(font)) / 2;
	MPrint(x, y, str);
	InvalidateRegion( x, y, x2, y2 );
}