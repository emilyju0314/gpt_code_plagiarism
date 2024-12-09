void Blt8BPPDataSubTo16BPPBuffer(UINT16* const buf, UINT32 const uiDestPitchBYTES, SGPVSurface* const hSrcVSurface, UINT8* const pSrcBuffer, UINT32 const src_pitch, INT32 const x, INT32 const y, SGPBox const* const rect)
{
	Assert(hSrcVSurface);
	Assert(pSrcBuffer);
	Assert(buf);

	CHECKV(x >= 0);
	CHECKV(y >= 0);

	UINT32 const LeftSkip   = rect->x;
	UINT32 const TopSkip    = rect->y * src_pitch;
	UINT32 const BlitLength = rect->w;
	UINT32       BlitHeight = rect->h;
	UINT32 const src_skip   = src_pitch - BlitLength;

	UINT32        const pitch     = uiDestPitchBYTES / 2;
	UINT8  const*       src       = pSrcBuffer + TopSkip + LeftSkip;
	UINT16*             dst       = buf + pitch * y + x;
	UINT16 const* const pal       = hSrcVSurface->p16BPPPalette;
	UINT32              line_skip = pitch - BlitLength;

	do
	{
		UINT32 w = BlitLength;
		do
		{
			*dst++ = pal[*src++];
		}
		while (--w != 0);
		src += src_skip;
		dst += line_skip;
	}
	while (--BlitHeight != 0);
}