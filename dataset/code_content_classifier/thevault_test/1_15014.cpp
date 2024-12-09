void Blt8BPPDataTo16BPPBufferTransZTranslucent( UINT16* const buf, UINT32 const uiDestPitchBYTES, UINT16* const zbuf, UINT16 const zval, HVOBJECT const hSrcVObject, INT32 const iX, INT32 const iY, UINT16 const usIndex )
{

	// Assertions
	Assert( hSrcVObject );
	Assert( buf );

	// Get Offsets from Index into structure
	ETRLEObject const& e      = hSrcVObject->SubregionProperties(usIndex);
	UINT32             height = e.usHeight;
	UINT32      const  width  = e.usWidth;

	// Add to start position of dest buffer
	INT32 const x = iX + e.sOffsetX;
	INT32 const y = iY + e.sOffsetY;

	// Validations
	CHECKV(x >= 0);
	CHECKV(y >= 0);

	UINT32 const  pitch           = uiDestPitchBYTES / 2;
	UINT8  const* src             = hSrcVObject->PixData(e);
	UINT16 * dst                  = buf + pitch * y + x;
	UINT16 * zdst                 = zbuf + pitch * y + x;
	UINT16 const* const pal       = hSrcVObject->CurrentShade();
	UINT32 line_skip              = pitch - width;
	UINT32 const translucent_mask = guiTranslucentMask;

	do
	{
		for (;;)
		{
			UINT8 data = *src++;

			if (data == 0) break;
			if (data & 0x80)
			{
				data 		&= 0x7F;
				dst 	+= data;
				zdst	+= data;
			}
			else
			{
				do
				{
					if (*zdst > zval) continue;
					*zdst = zval;
					*dst =
						((pal[*src] >> 1) & translucent_mask) +
						((*dst      >> 1) & translucent_mask);
				}
				while (++src, ++dst, ++zdst, --data > 0);
			}
		}
		dst 	+= line_skip;
		zdst	+= line_skip;
	}
	while (--height > 0);
}