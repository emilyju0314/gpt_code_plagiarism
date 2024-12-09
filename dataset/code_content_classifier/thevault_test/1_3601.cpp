void CShaderAPIDx8::CopyBitsFromHostSurface( IDirect3DSurface* pSurfaceBits, 
	const Rect_t &dstRect, unsigned char *pData, ImageFormat srcFormat, ImageFormat dstFormat, int nDstStride )
{
	// Copy out the bits...
	RECT rect;
	rect.left   = dstRect.x; 
	rect.right  = dstRect.x + dstRect.width; 
	rect.top    = dstRect.y; 
	rect.bottom = dstRect.y + dstRect.height;

	D3DLOCKED_RECT lockedRect;
	HRESULT hr;
	int flags = D3DLOCK_READONLY | D3DLOCK_NOSYSLOCK;
	hr = pSurfaceBits->LockRect( &lockedRect, &rect, flags );
	if ( !FAILED( hr ) )
	{
		unsigned char *pImage = (unsigned char *)lockedRect.pBits;
		ShaderUtil()->ConvertImageFormat( (unsigned char *)pImage, srcFormat,
			pData, dstFormat, dstRect.width, dstRect.height, lockedRect.Pitch, nDstStride );

		hr = pSurfaceBits->UnlockRect( );
	}
}