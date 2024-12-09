void Blt8BPPDataTo16BPPBufferOutline(UINT16* const buf, UINT32 const uiDestPitchBYTES, SGPVObject const* const hSrcVObject, INT32 const iX, INT32 const iY, UINT16 const usIndex, INT16 const outline)
{
	Assert(hSrcVObject);
	Assert(buf);

	// Get offsets from index into structure
	ETRLEObject const& e      = hSrcVObject->SubregionProperties(usIndex);
	UINT32             height = e.usHeight;
	UINT32      const  width  = e.usWidth;

	// Add to start position of dest buffer
	INT32 const x = iX + e.sOffsetX;
	INT32 const y = iY + e.sOffsetY;

	CHECKV(x >= 0);
	CHECKV(y >= 0);

	UINT8  const*       src       = hSrcVObject->PixData(e);
	UINT32        const pitch     = uiDestPitchBYTES / 2;
	UINT16*             dst       = buf + pitch * y + x;
	UINT32              line_skip = pitch - width;
	UINT16 const* const pal       = hSrcVObject->CurrentShade();

	for (;;)
	{
		UINT8 data = *src++;
		if (data == 0)
		{
			if (--height == 0) break;
			dst += line_skip;
		}
		else if (data & 0x80)
		{
			dst += data & 0x7F;
		}
		else
		{
			do
			{
				UINT8 const px = *src++;
				if (px != 254)
				{
					*dst = pal[px];
				}
				else if (outline != SGP_TRANSPARENT)
				{
					*dst = outline;
				}
				++dst;
			}
			while (--data != 0);
		}
	}
}