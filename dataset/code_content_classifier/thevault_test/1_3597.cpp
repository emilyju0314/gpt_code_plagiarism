IDirect3DSurface* CShaderAPIDx8::GetFrontBufferImage( ImageFormat& format )
{
#if !defined( _X360 )
	int w, h;
	GetBackBufferDimensions( w, h );

	HRESULT hr;
	IDirect3DSurface *pFullScreenSurfaceBits = 0;
	hr = Dx9Device()->CreateOffscreenPlainSurface( w, h, 
		D3DFMT_A8R8G8B8, D3DPOOL_SCRATCH, &pFullScreenSurfaceBits, NULL );
	if (FAILED(hr))
		return 0;

	hr = Dx9Device()->GetFrontBufferData( 0, pFullScreenSurfaceBits );
	if (FAILED(hr))
		return 0;

	int windowWidth, windowHeight;
	GetWindowSize( windowWidth, windowHeight );
	
	IDirect3DSurface *pSurfaceBits = 0;
	hr = Dx9Device()->CreateOffscreenPlainSurface( windowWidth, windowHeight,
		D3DFMT_A8R8G8B8, D3DPOOL_SCRATCH, &pSurfaceBits, NULL );
	Assert( hr == D3D_OK );
	
	POINT pnt;
	pnt.x = pnt.y = 0;
#ifdef _WIN32
	BOOL result = ClientToScreen( ( HWND )m_hWnd, &pnt );
#else
	BOOL result = ClientToScreen( (VD3DHWND)m_hWnd, &pnt );
#endif
	Assert( result );

	RECT srcRect;
	srcRect.left = pnt.x;
	srcRect.top = pnt.y;
	srcRect.right = pnt.x + windowWidth;
	srcRect.bottom = pnt.y + windowHeight;

	POINT dstPnt;
	dstPnt.x = dstPnt.y = 0;
	
	D3DLOCKED_RECT lockedSrcRect;
	hr = pFullScreenSurfaceBits->LockRect( &lockedSrcRect, &srcRect, D3DLOCK_READONLY );
	Assert( hr == D3D_OK );
	
	D3DLOCKED_RECT lockedDstRect;
	hr = pSurfaceBits->LockRect( &lockedDstRect, NULL, 0 );
	Assert( hr == D3D_OK );

	int i;
	for( i = 0; i < windowHeight; i++ )
	{
		memcpy( ( unsigned char * )lockedDstRect.pBits + ( i * lockedDstRect.Pitch ), 
			    ( unsigned char * )lockedSrcRect.pBits + ( i * lockedSrcRect.Pitch ),
				windowWidth * 4 ); // hack . .  what if this is a different format?
	}
	hr = pSurfaceBits->UnlockRect();
	Assert( hr == D3D_OK );
	hr = pFullScreenSurfaceBits->UnlockRect();
	Assert( hr == D3D_OK );

	pFullScreenSurfaceBits->Release();

	format = ImageLoader::D3DFormatToImageFormat( D3DFMT_A8R8G8B8 );
	return pSurfaceBits;
#else
	Assert( 0 );
	return NULL;
#endif
}