BOOLEAN CheckVideoObjectScreenCoordinateInData(HVOBJECT hSrcVObject, UINT16 usIndex, INT32 iTestX, INT32 iTestY)
{
	BOOLEAN fDataFound = FALSE;
	INT32   iTestPos, iStartPos;

	// Assertions
	Assert( hSrcVObject != NULL );

	// Get Offsets from Index into structure
	ETRLEObject const& pTrav    = hSrcVObject->SubregionProperties(usIndex);
	UINT32             usHeight = pTrav.usHeight;
	UINT32      const  usWidth  = pTrav.usWidth;

	// Calculate test position we are looking for!
	// Calculate from 0, 0 at top left!
	iTestPos	= ( ( usHeight - iTestY ) * usWidth ) + iTestX;
	iStartPos	= 0;

	UINT8 const* SrcPtr = hSrcVObject->PixData(pTrav);

	do
	{
		for (;;)
		{
			UINT8 PxCount = *SrcPtr++;
			if (PxCount == 0) break;
			if (PxCount & 0x80)
			{
				PxCount &= 0x7F;
			}
			else
			{
				if (iStartPos < iTestPos && iTestPos <= iStartPos + PxCount) return TRUE;
				SrcPtr += PxCount;
			}
			iStartPos += PxCount;
		}
		if (iStartPos >= iTestPos) break;
	}
	while (--usHeight > 0);
	return(fDataFound);

}