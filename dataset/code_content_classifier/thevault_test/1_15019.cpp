void Blt8BPPDataTo16BPPBufferTransZ(UINT16* const buf, UINT32 const uiDestPitchBYTES, UINT16* const zbuf, UINT16 const zval, HVOBJECT const hSrcVObject, INT32 const iX, INT32 const iY, UINT16 const usIndex)
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

	// Validations
	CHECKV(x >= 0);
	CHECKV(y >= 0);

	UINT8 const*        src       = hSrcVObject->PixData(e);
	UINT32        const pitch     = uiDestPitchBYTES / 2;
	UINT16*             dst       = buf  + pitch * y + x;
	UINT16*             zdst      = zbuf + pitch * y + x;
	UINT16 const* const pal       = hSrcVObject->CurrentShade();
	UINT32              line_skip = pitch - width;

	for (;;)
	{
		UINT8 data = *src++;
		if (data == 0)
		{
			if (--height == 0) break;
			dst  += line_skip;
			zdst += line_skip;
		}
		else if (data & 0x80)
		{
			data &= 0x7F;
			dst  += data;
			zdst += data;
		}
		else
		{
			do
			{
				if (*zdst <= zval)
				{
					*zdst = zval;
					*dst  = pal[*src];
				}
				++src;
				++dst;
				++zdst;
			}
			while (--data != 0);
		}
	}
}