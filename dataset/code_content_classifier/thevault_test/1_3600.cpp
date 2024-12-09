IDirect3DSurface* CShaderAPIDx8::GetBackBufferImageHDR( Rect_t *pSrcRect, Rect_t *pDstRect, ImageFormat& format )
{
#if !defined( _X360 )
	HRESULT hr;
	IDirect3DSurface *pSurfaceBits = 0;
	IDirect3DSurface *pTmpSurface = NULL;

	// Get the back buffer
	IDirect3DSurface* pBackBuffer;
	hr = Dx9Device()->GetRenderTarget( 0, &pBackBuffer );
	if (FAILED(hr))
		return 0;

	// Find about its size and format
	D3DSURFACE_DESC desc;
	D3DTEXTUREFILTERTYPE filter;
	
	hr = pBackBuffer->GetDesc( &desc );
	if (FAILED(hr))
		goto CleanUp;

	filter = ((pDstRect->width != pSrcRect->width) || (pDstRect->height != pSrcRect->height)) ? D3DTEXF_LINEAR : D3DTEXF_NONE;

	if ( ( pDstRect->x + pDstRect->width <= SMALL_BACK_BUFFER_SURFACE_WIDTH ) && 
		 ( pDstRect->y + pDstRect->height <= SMALL_BACK_BUFFER_SURFACE_HEIGHT ) )
	{
		if (!m_pSmallBackBufferFP16TempSurface)
		{
			hr = Dx9Device()->CreateRenderTarget( 
				SMALL_BACK_BUFFER_SURFACE_WIDTH, SMALL_BACK_BUFFER_SURFACE_HEIGHT, 
				desc.Format, D3DMULTISAMPLE_NONE, 0, TRUE, &m_pSmallBackBufferFP16TempSurface,
				NULL );
		}
		pTmpSurface = m_pSmallBackBufferFP16TempSurface;
		pTmpSurface->AddRef();

		desc.Width = SMALL_BACK_BUFFER_SURFACE_WIDTH;
		desc.Height = SMALL_BACK_BUFFER_SURFACE_HEIGHT;

		RECT srcRect, destRect;
		RectToRECT( pSrcRect, srcRect );
		RectToRECT( pDstRect, destRect );
		hr = Dx9Device()->StretchRect( pBackBuffer, &srcRect, pTmpSurface, &destRect, filter );
		if ( FAILED(hr) )
			goto CleanUp;
	}
	else
	{
		// Normally we would only have to create a separate render target here and StretchBlt to it first
		// if AA was enabled, but certain machines/drivers get reboots if we do GetRenderTargetData 
		// straight off the backbuffer.
		hr = Dx9Device()->CreateRenderTarget( desc.Width, desc.Height, desc.Format,
			D3DMULTISAMPLE_NONE, 0, TRUE, &pTmpSurface, NULL );
		if ( FAILED(hr) )
			goto CleanUp;

		hr = Dx9Device()->StretchRect( pBackBuffer, NULL, pTmpSurface, NULL, filter );
		if ( FAILED(hr) )
			goto CleanUp;
	}

	// Create a buffer the same size and format
	hr = Dx9Device()->CreateOffscreenPlainSurface( desc.Width, desc.Height, 
		desc.Format, D3DPOOL_SYSTEMMEM, &pSurfaceBits, NULL );
	if (FAILED(hr))
		goto CleanUp;

	// Blit from the back buffer to our scratch buffer
	hr = Dx9Device()->GetRenderTargetData( pTmpSurface ? pTmpSurface : pBackBuffer, pSurfaceBits );
	if (FAILED(hr))
		goto CleanUp2;

	format = ImageLoader::D3DFormatToImageFormat(desc.Format);
	if ( pTmpSurface )
	{
		pTmpSurface->Release();
	}
	pBackBuffer->Release();
	return pSurfaceBits;

CleanUp2:
	pSurfaceBits->Release();

CleanUp:
	if ( pTmpSurface )
	{
		pTmpSurface->Release();
	}

	pBackBuffer->Release();
#else
	Assert( 0 );
#endif
	return 0;
}