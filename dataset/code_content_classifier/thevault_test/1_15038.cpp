static void Blt16BPPBufferPixelateRectWithColor(UINT16* pBuffer, UINT32 uiDestPitchBYTES, SGPRect* area, const UINT8 Pattern[8][8], UINT16 usColor)
{
	INT32  width, height;
	UINT32 LineSkip;
	UINT16 *DestPtr;
	INT32	iLeft, iTop, iRight, iBottom;

	// Assertions
	Assert( pBuffer != NULL );
	Assert( Pattern != NULL );

	iLeft=__max(ClippingRect.iLeft, area->iLeft);
	iTop=__max(ClippingRect.iTop, area->iTop);
	iRight=__min(ClippingRect.iRight-1, area->iRight);
	iBottom=__min(ClippingRect.iBottom-1, area->iBottom);

	DestPtr=(pBuffer+(iTop*(uiDestPitchBYTES/2))+iLeft);
	width=iRight-iLeft+1;
	height=iBottom-iTop+1;
	LineSkip=(uiDestPitchBYTES-(width*2));

	CHECKV(width  >= 1);
	CHECKV(height >= 1);

	UINT32 row = 0;
	do
	{
		UINT32 col = 0;
		UINT32 w = width;

		do
		{
			if (Pattern[row][col] != 0) *DestPtr = usColor;
			DestPtr++;
			col = (col + 1) % 8;
		}
		while (--w > 0);
		DestPtr += LineSkip / 2;
		row = (row + 1) % 8;
	}
	while (--height > 0);
}