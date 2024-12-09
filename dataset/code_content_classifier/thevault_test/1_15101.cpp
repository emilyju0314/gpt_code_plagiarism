static void GDirty(INT16 x, INT16 y, const ST::utf32_buffer& codepoints)
{
	UINT16 const length = StringPixLength(codepoints, FontDefault);
	if (length > 0)
	{
		UINT16 const height = GetFontHeight(FontDefault);
		RegisterBackgroundRectSingleFilled(x, y, length, height);
	}
}