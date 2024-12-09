void MPrintEditor(INT16 x, INT16 y, const ST::string& str)
{
	UINT16 uiStringLength, uiStringHeight;

	uiStringLength = StringPixLength( str, FontDefault );
	uiStringHeight = GetFontHeight( FontDefault );

	ClearTaskbarRegion( x, y, (INT16)(x+uiStringLength), (INT16)(y+uiStringHeight) );
	MPrint(x, TASKBAR_Y + y, str);
}