void Blt8BPPDataTo16BPPBufferTransZPixelateObscured( UINT16 *pBuffer, UINT32 uiDestPitchBYTES, UINT16 *pZBuffer, UINT16 usZValue, HVOBJECT hSrcVObject, INT32 iX, INT32 iY, UINT16 usIndex )
{
	UINT32 LineSkip;
	UINT8  *DestPtr, *ZPtr;
	UINT32 uiLineFlag;

	// Assertions
	Assert( hSrcVObject != NULL );
	Assert( pBuffer != NULL );

	// Get Offsets from Index into structure
	ETRLEObject const& pTrav = hSrcVObject->SubregionProperties(usIndex);
	UINT32             usHeight = pTrav.usHeight;
	UINT32      const  usWidth  = pTrav.usWidth;

	// Add to start position of dest buffer
	INT32 const iTempX = iX + pTrav.sOffsetX;
	INT32 const iTempY = iY + pTrav.sOffsetY;

	// Validations
	CHECKV(iTempX >= 0);
	CHECKV(iTempY >= 0);

	UINT8 const* SrcPtr = hSrcVObject->PixData(pTrav);
	DestPtr = (UINT8 *)pBuffer + (uiDestPitchBYTES*iTempY) + (iTempX*2);
	ZPtr = (UINT8 *)pZBuffer + (uiDestPitchBYTES*iTempY) + (iTempX*2);
	UINT16 const* const p16BPPPalette = hSrcVObject->CurrentShade();
	LineSkip=(uiDestPitchBYTES-(usWidth*2));
	uiLineFlag=(iTempY&1);

	do
	{
		for (;;)
		{
			UINT8 data = *SrcPtr++;

			if (data == 0) break;
			if (data & 0x80)
			{
				data &= 0x7F;
				DestPtr += 2 * data;
				ZPtr += 2 * data;
			}
			else
			{
				do
				{
					if (*(UINT16*)ZPtr < usZValue)
					{
						*(UINT16*)ZPtr = usZValue;
					}
					else
					{
						if (uiLineFlag != (((uintptr_t)DestPtr & 2) != 0)) continue;
					}
					*(UINT16*)DestPtr = p16BPPPalette[*SrcPtr];
				}
				while (SrcPtr++, DestPtr += 2, ZPtr += 2, --data > 0);
			}
		}
		DestPtr += LineSkip;
		ZPtr += LineSkip;
		uiLineFlag ^= 1;
	}
	while (--usHeight > 0);
}