UINT16 DisplayWrappedString(UINT16 x, UINT16 y, UINT16 w, UINT8 gap, SGPFont font, UINT8 foreground, const ST::utf32_buffer& codepoints, UINT8 background, UINT32 flags)
{
	UINT16       total_h = 0;
	UINT16 const h       = GetFontHeight(font) + gap;
	for (WRAPPED_STRING* i = LineWrap(font, w, codepoints); i;)
	{
		DrawTextToScreen(i->codepoints, x, y, w, font, foreground, background, flags);
		WRAPPED_STRING* const del = i;
		i = i->pNextWrappedString;
		delete del;
		total_h += h;
		y       += h;
	}
	return total_h;
}