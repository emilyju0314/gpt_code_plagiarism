void Blt8BPPDataTo16BPPBufferShadowClip( UINT16 *pBuffer, UINT32 uiDestPitchBYTES, HVOBJECT hSrcVObject, INT32 iX, INT32 iY, UINT16 usIndex, SGPRect *clipregion)
{
	UINT8  *DestPtr;
	UINT32 LineSkip;
	INT32  LeftSkip, RightSkip, TopSkip, BottomSkip, BlitLength, BlitHeight;
	INT32  ClipX1, ClipY1, ClipX2, ClipY2;

	// Assertions
	Assert( hSrcVObject != NULL );
	Assert( pBuffer != NULL );

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
	LeftSkip=__min(ClipX1 - MIN(ClipX1, iTempX), (INT32)usWidth);
	RightSkip=__min(MAX(ClipX2, (iTempX+(INT32)usWidth)) - ClipX2, (INT32)usWidth);
	TopSkip=__min(ClipY1 - __min(ClipY1, iTempY), (INT32)usHeight);
	BottomSkip=__min(__max(ClipY2, (iTempY+(INT32)usHeight)) - ClipY2, (INT32)usHeight);

	// calculate the remaining rows and columns to blit
	BlitLength=((INT32)usWidth-LeftSkip-RightSkip);
	BlitHeight=((INT32)usHeight-TopSkip-BottomSkip);

	// whole thing is clipped
	if((LeftSkip >=(INT32)usWidth) || (RightSkip >=(INT32)usWidth))
		return;

	// whole thing is clipped
	if((TopSkip >=(INT32)usHeight) || (BottomSkip >=(INT32)usHeight))
		return;

	UINT8 const* SrcPtr = hSrcVObject->PixData(pTrav);
	DestPtr = (UINT8 *)pBuffer + (uiDestPitchBYTES*(iTempY+TopSkip)) + ((iTempX+LeftSkip)*2);
	LineSkip=(uiDestPitchBYTES-(BlitLength*2));

	UINT32 LSCount;
	UINT32 PxCount;

	while (TopSkip > 0)
	{
		for (;;)
		{
			PxCount = *SrcPtr++;
			if (PxCount & 0x80) continue;
			if (PxCount == 0) break;
			SrcPtr += PxCount;
		}
		TopSkip--;
	}

	do
	{
		for (LSCount = LeftSkip; LSCount > 0; LSCount -= PxCount)
		{
			PxCount = *SrcPtr++;
			if (PxCount & 0x80)
			{
				PxCount &= 0x7F;
				if (PxCount > static_cast<UINT32>(LSCount))
				{
					PxCount -= LSCount;
					LSCount = BlitLength;
					goto BlitTransparent;
				}
			}
			else
			{
				if (PxCount > static_cast<UINT32>(LSCount))
				{
					SrcPtr += LSCount;
					PxCount -= LSCount;
					LSCount = BlitLength;
					goto BlitNonTransLoop;
				}
				SrcPtr += PxCount;
			}
		}

		LSCount = BlitLength;
		while (LSCount > 0)
		{
			PxCount = *SrcPtr++;
			if (PxCount & 0x80)
			{
BlitTransparent: // skip transparent pixels
				PxCount &= 0x7F;
				if (PxCount > static_cast<UINT32>(LSCount)) PxCount = LSCount;
				LSCount -= PxCount;
				DestPtr += 2 * PxCount;
			}
			else
			{
BlitNonTransLoop: // blit non-transparent pixels
				SrcPtr += PxCount;
				if (PxCount > static_cast<UINT32>(LSCount)) PxCount = LSCount;
				LSCount -= PxCount;

				do
				{
					*(UINT16*)DestPtr = ShadeTable[*(UINT16*)DestPtr];
					DestPtr += 2;
				}
				while (--PxCount > 0);
			}
		}

		while (*SrcPtr++ != 0) {} // skip along until we hit and end-of-line marker
		DestPtr += LineSkip;
	}
	while (--BlitHeight > 0);
}