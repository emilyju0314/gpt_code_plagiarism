void Blt8BPPDataTo16BPPBufferTransShadow(UINT16* pBuffer, UINT32 uiDestPitchBYTES, HVOBJECT hSrcVObject, INT32 iX, INT32 iY, UINT16 usIndex, const UINT16* p16BPPPalette)
{
	UINT8  *DestPtr;
	UINT32 LineSkip;

	// Assertions
	Assert( hSrcVObject != NULL );
	Assert( pBuffer != NULL );

	// Get Offsets from Index into structure
	ETRLEObject const& pTrav = hSrcVObject->SubregionProperties(usIndex);
	UINT32          usHeight = pTrav.usHeight;
	UINT32   const  usWidth  = pTrav.usWidth;

	// Add to start position of dest buffer
	INT32 const iTempX = iX + pTrav.sOffsetX;
	INT32 const iTempY = iY + pTrav.sOffsetY;

	// Validations
	CHECKV(iTempX >= 0);
	CHECKV(iTempY >= 0);

	UINT8 const* SrcPtr = hSrcVObject->PixData(pTrav);
	DestPtr = (UINT8 *)pBuffer + (uiDestPitchBYTES*iTempY) + (iTempX*2);
	LineSkip=(uiDestPitchBYTES-(usWidth*2));

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
			}
			else
			{
				do
				{
					UINT8 px = *SrcPtr++;

					if (px == 254)
					{
						*(UINT16*)DestPtr = ShadeTable[2 * (*(UINT16*)DestPtr)];
					}
					else
					{
						*(UINT16*)DestPtr = p16BPPPalette[2 * px];
					}
					DestPtr += 2;
				}
				while (--data > 0);
			}
		}
		DestPtr += LineSkip;
	}
	while (--usHeight > 0);
}