void Blt8BPPDataTo16BPPBuffer( UINT16 *pBuffer, UINT32 uiDestPitchBYTES, SGPVSurface* hSrcVSurface, UINT8 *pSrcBuffer, INT32 iX, INT32 iY)
{
	INT32  iTempX, iTempY;

	// Assertions
	Assert( hSrcVSurface != NULL );
	Assert( pSrcBuffer != NULL );
	Assert( pBuffer != NULL );

	// Get Offsets from Index into structure
	UINT32 const usWidth  = hSrcVSurface->Width();
	UINT32 const usHeight = hSrcVSurface->Height();

	// Add to start position of dest buffer
	iTempX = iX;
	iTempY = iY;

	// Validations
	CHECKV(iTempX >= 0);
	CHECKV(iTempY >= 0);

	UINT8*  SrcPtr        = pSrcBuffer;
	UINT16* DestPtr       = pBuffer + uiDestPitchBYTES / 2 * iTempY + iTempX;
	UINT16* p16BPPPalette = hSrcVSurface->p16BPPPalette;

	for (size_t h = usHeight; h != 0; --h)
	{
		for (size_t w = 0; w != usWidth; ++w)
		{
			DestPtr[w] = p16BPPPalette[SrcPtr[w]];
		}

		SrcPtr  += usWidth;
		DestPtr += uiDestPitchBYTES / 2;
	}
}