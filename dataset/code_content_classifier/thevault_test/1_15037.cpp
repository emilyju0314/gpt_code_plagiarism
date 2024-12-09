void Blt8BPPDataTo16BPPBufferHalf(UINT16* const dst_buf, UINT32 const uiDestPitchBYTES, SGPVSurface* const src_surface, UINT8 const* const src_buf, UINT32 const src_pitch, INT32 const x, INT32 const y, SGPBox const* const rect)
{
	Assert(src_surface);
	Assert(src_buf);
	Assert(dst_buf);

	CHECKV(x >= 0);
	CHECKV(y >= 0);

	UINT8 const* src = src_buf;
	UINT32       width;
	UINT32       height;
	if (rect)
	{
		width  = rect->w;
		height = rect->h;
		CHECKV(0 < width  && width  <= src_surface->Width());
		CHECKV(0 < height && height <= src_surface->Height());

		src += src_pitch * rect->y + rect->x;
	}
	else
	{
		width  = src_surface->Width();
		height = src_surface->Height();
	}

	UINT16*             dst      = dst_buf + uiDestPitchBYTES / 2 * y + x;
	UINT32        const src_skip = (src_pitch - width / 2) * 2;
	UINT32        const dst_skip = uiDestPitchBYTES / 2 - width / 2;
	UINT16 const* const pal      = src_surface->p16BPPPalette;

	height /= 2;
	do
	{
		UINT32 w = width / 2;
		do
		{
			*dst++ = pal[*src];
			src += 2;
		}
		while (--w > 0);
		src += src_skip;
		dst += dst_skip;
	}
	while (--height > 0);
}