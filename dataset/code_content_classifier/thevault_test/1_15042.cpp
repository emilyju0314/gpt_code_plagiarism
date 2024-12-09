BOOLEAN BltIsClipped(const SGPVObject* const hSrcVObject, const INT32 iX, const INT32 iY, const UINT16 usIndex, const SGPRect* const clipregion)
{
	INT32  ClipX1, ClipY1, ClipX2, ClipY2;

	// Assertions
	Assert( hSrcVObject != NULL );

	// Get Offsets from Index into structure
	ETRLEObject const& pTrav = hSrcVObject->SubregionProperties(usIndex);
	UINT32      const  usHeight = pTrav.usHeight;
	UINT32      const  usWidth  = pTrav.usWidth;

	// Add to start position of dest buffer
	INT32 const iTempX = iX + pTrav.sOffsetX;
	INT32 const iTempY = iY + pTrav.sOffsetY;

	if(clipregion==NULL)
	{
		ClipX1=ClippingRect.iLeft;
		ClipY1=ClippingRect.iTop;
		ClipX2=ClippingRect.iRight;
		ClipY2=ClippingRect.iBottom;
	}
	else
	{
		ClipX1=clipregion->iLeft;
		ClipY1=clipregion->iTop;
		ClipX2=clipregion->iRight;
		ClipY2=clipregion->iBottom;
	}


	// Calculate rows hanging off each side of the screen
	if(__min(ClipX1 - MIN(ClipX1, iTempX), (INT32)usWidth))
		return(TRUE);

	if(__min(MAX(ClipX2, (iTempX+(INT32)usWidth)) - ClipX2, (INT32)usWidth))
		return(TRUE);

	if(__min(ClipY1 - __min(ClipY1, iTempY), (INT32)usHeight))
		return(TRUE);

	if(__min(__max(ClipY2, (iTempY+(INT32)usHeight)) - ClipY2, (INT32)usHeight))
		return(TRUE);

	return(FALSE);
}