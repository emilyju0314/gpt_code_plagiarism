D3DCOLOR CShaderAPIDx8::GetActualClearColor( D3DCOLOR clearColor )
{
	bool bConvert = !IsX360() && m_TransitionTable.CurrentState().m_bLinearColorSpaceFrameBufferEnable;

#if defined( _X360 )
	// The PC disables SRGBWrite when clearing so that the clear color won't get gamma converted
	// The 360 cannot disable that state, and thus compensates for the sRGB conversion
	// the desired result is the clear color written to the RT as-is
	if ( clearColor & D3DCOLOR_ARGB( 0, 255, 255, 255 ) )
	{
		IDirect3DSurface *pRTSurface = NULL;
		Dx9Device()->GetRenderTarget( 0, &pRTSurface );
		if ( pRTSurface )
		{
			D3DSURFACE_DESC desc;
			HRESULT hr = pRTSurface->GetDesc( &desc );
			if ( !FAILED( hr ) && IS_D3DFORMAT_SRGB( desc.Format ) )
			{
				bConvert = true;
			}
			pRTSurface->Release();
		}
	}
#endif

	if ( bConvert )
	{
		// HDRFIXME: need to make sure this works this way.
		// HDRFIXME: Is there a helper function that'll do this easier?
		// convert clearColor from gamma to linear since our frame buffer is linear.
		Vector vecGammaColor;
		vecGammaColor.x = ( 1.0f / 255.0f ) * ( ( clearColor >> 16 ) & 0xff );
		vecGammaColor.y = ( 1.0f / 255.0f ) * ( ( clearColor >> 8 ) & 0xff );
		vecGammaColor.z = ( 1.0f / 255.0f ) * ( clearColor & 0xff );
		Vector vecLinearColor;
		vecLinearColor.x = GammaToLinear( vecGammaColor.x );
		vecLinearColor.y = GammaToLinear( vecGammaColor.y );
		vecLinearColor.z = GammaToLinear( vecGammaColor.z );
		clearColor &= D3DCOLOR_RGBA( 0, 0, 0, 255 );
		clearColor |= D3DCOLOR_COLORVALUE( vecLinearColor.x, vecLinearColor.y, vecLinearColor.z, 0.0f );
	}

	return clearColor;
}