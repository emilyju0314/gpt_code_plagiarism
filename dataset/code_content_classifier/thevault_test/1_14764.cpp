static void DrawGenericButton(const GUI_BUTTON* b)
{
	// Select the graphics to use depending on the current state of the button
	HVOBJECT BPic;
	if (!b->Enabled())
	{
		BPic = GenericButtonOffNormal;
		switch (b->bDisabledStyle)
		{
			case GUI_BUTTON::DISABLED_STYLE_DEFAULT:
				gbDisabledButtonStyle = !b->codepoints.empty() ?
					GUI_BUTTON::DISABLED_STYLE_SHADED :
					GUI_BUTTON::DISABLED_STYLE_HATCHED;
				break;

			case GUI_BUTTON::DISABLED_STYLE_HATCHED:
			case GUI_BUTTON::DISABLED_STYLE_SHADED:
				gbDisabledButtonStyle = b->bDisabledStyle;
				break;
		}
	}
	else if (b->Clicked())
	{
		if  (b->Area.uiFlags & MSYS_MOUSE_IN_AREA && GenericButtonOnHilite != NULL && gfRenderHilights)
		{
			BPic = GenericButtonOnHilite;
		}
		else
		{
			BPic = GenericButtonOnNormal;
		}
	}
	else
	{
		if (b->Area.uiFlags & MSYS_MOUSE_IN_AREA && GenericButtonOffHilite != NULL && gfRenderHilights)
		{
			BPic = GenericButtonOffHilite;
		}
		else
		{
			BPic = GenericButtonOffNormal;
		}
	}

	const INT32 iBorderWidth  = 3;
	const INT32 iBorderHeight = 2;

	// Compute the number of button "chunks" needed to be blitted
	INT32 const width         = b->W();
	INT32 const height        = b->H();
	const INT32 NumChunksWide = width  / iBorderWidth;
	INT32       NumChunksHigh = height / iBorderHeight;
	const INT32 hremain       = height % iBorderHeight;
	const INT32 wremain       = width  % iBorderWidth;

	INT32 const bx = b->X();
	INT32 const by = b->Y();
	INT32 const cx = bx + (NumChunksWide - 1) * iBorderWidth  + wremain;
	INT32 const cy = by + (NumChunksHigh - 1) * iBorderHeight + hremain;

	// Fill the button's area with the button's background color
	ColorFillVideoSurfaceArea(ButtonDestBuffer, b->X(), b->Y(), b->BottomRightX(), b->BottomRightY(), GenericButtonFillColors);

	SGPVSurface::Lock l(ButtonDestBuffer);
	UINT16* const pDestBuf         = l.Buffer<UINT16>();
	UINT32  const uiDestPitchBYTES = l.Pitch();

	SGPRect ClipRect;
	GetClippingRect(&ClipRect);

	// Draw the button's borders and corners (horizontally)
	for (INT32 q = 0; q < NumChunksWide; q++)
	{
		INT32 const ImgNum = (q == 0 ? 0 : 1);
		INT32 const x = bx + q * iBorderWidth;
		Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, x,  by, ImgNum,     &ClipRect);
		Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, x,  cy, ImgNum + 5, &ClipRect);
	}
	// Blit the right side corners
	Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, cx, by, 2, &ClipRect);
	Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, cx, cy, 7, &ClipRect);
	// Draw the vertical members of the button's borders
	NumChunksHigh--;

	if (hremain != 0)
	{
		INT32 const y = by + NumChunksHigh * iBorderHeight - iBorderHeight + hremain;
		Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, bx, y, 3, &ClipRect);
		Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, cx, y, 4, &ClipRect);
	}

	for (INT32 q = 1; q < NumChunksHigh; q++)
	{
		INT32 const y = by + q * iBorderHeight;
		Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, bx, y, 3, &ClipRect);
		Blt8BPPDataTo16BPPBufferTransparentClip(pDestBuf, uiDestPitchBYTES, BPic, cx, y, 4, &ClipRect);
	}
}