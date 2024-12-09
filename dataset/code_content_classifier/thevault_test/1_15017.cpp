void Blt16BPPTo16BPP(UINT16 *pDest, UINT32 uiDestPitch, UINT16 *pSrc, UINT32 uiSrcPitch, INT32 iDestXPos, INT32 iDestYPos, INT32 iSrcXPos, INT32 iSrcYPos, UINT32 uiWidth, UINT32 uiHeight)
{
	UINT32 i;

	for (i = 0; i < uiHeight; i++)
	{
		memcpy(
			(UINT8*)pDest + uiDestPitch * (iDestYPos + i) + 2 * iDestXPos,
			(UINT8*)pSrc  + uiSrcPitch  * (iSrcYPos  + i) + 2 * iSrcXPos,
			uiWidth * 2
		);
	}
}