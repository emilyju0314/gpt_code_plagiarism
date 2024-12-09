void CShaderAPIDx8::ReadPixelsAsync( int x, int y, int width, int height, unsigned char *pData, ImageFormat dstFormat, ITexture *pRenderTargetTexture, CThreadEvent *pPixelsReadEvent )
{
	TM_ZONE( TELEMETRY_LEVEL1, TMZF_NONE, "%s", __FUNCTION__ );

	Rect_t rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;

	if ( IsPC() || !IsX360() )
	{
		if ( pRenderTargetTexture != NULL )
		{
			s_format = pRenderTargetTexture->GetImageFormat();
			ShaderAPITextureHandle_t hRenderTargetTexture = ShaderUtil()->GetShaderAPITextureBindHandle( pRenderTargetTexture, 0, 0 );

			//render targets can't be locked, luckily we can copy the surface to system memory and lock that.
			if ( IDirect3DSurface* pRTSurface = GetTextureSurface( hRenderTargetTexture ) )
			{
				D3DSURFACE_DESC surfaceDesc;
				pRTSurface->GetDesc( &surfaceDesc );

				Assert( !IsX360() );

				HRESULT hr = Dx9Device()->CreateOffscreenPlainSurface( surfaceDesc.Width, surfaceDesc.Height, surfaceDesc.Format, D3DPOOL_SYSTEMMEM, &s_pSystemSurface, NULL );
				Assert( SUCCEEDED( hr ) );

				if ( s_pSystemSurface != NULL )
				{
					s_pSystemSurface->GetDesc( &surfaceDesc );

					hr = Dx9Device()->GetRenderTargetData( pRTSurface, s_pSystemSurface );
					Assert( SUCCEEDED( hr ) );
				}

				//pretend this is the texture level we originally grabbed with GetSurfaceLevel() and continue on
				pRTSurface->Release();
			}
		}
		else
		{
			s_pSystemSurface = GetBackBufferImage( &rect, &rect, s_format );
		}
	}
	else
	{
#if defined( _X360 )
		Assert( 0 ); // not supported
#endif
	}

	// if the caller gave us a thread event, then signal the event
	if ( pPixelsReadEvent )
	{
		pPixelsReadEvent->Set();
	}
}