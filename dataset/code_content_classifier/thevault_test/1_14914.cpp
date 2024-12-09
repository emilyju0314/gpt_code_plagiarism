void DrawTextToScreen(const ST::utf32_buffer& codepoints, UINT16 x, UINT16 y, UINT16 max_w, SGPFont font, UINT8 foreground, UINT8 background, UINT32 flags)
{
	if (flags & DONT_DISPLAY_TEXT) return;

	INT16 const w = flags & (CENTER_JUSTIFIED | RIGHT_JUSTIFIED | TEXT_SHADOWED | INVALIDATE_TEXT) ?
		StringPixLength(codepoints, font) : 0;

	if (flags & CENTER_JUSTIFIED)
	{
		x += (max_w - w) / 2;
	}
	else if (flags & RIGHT_JUSTIFIED)
	{
		x += max_w - w;
	}

	if (flags & TEXT_SHADOWED)
	{
		UINT16 const h = GetFontHeight(font);
		FRAME_BUFFER->ShadowRect(x - 1, y - 1, x + w, y + h);
	}

	SetFont(font);
	SetFontForeground(foreground);
	SetFontBackground(background);
	if (flags & MARK_DIRTY)
	{
		GDirtyPrint(x, y, codepoints);
	}
	else
	{
		MPrint(x, y, codepoints);
	}

	if (flags & INVALIDATE_TEXT)
	{
		UINT16 const h = GetFontHeight(font);
		InvalidateRegion(x, y, x + w, y + h);
	}
}