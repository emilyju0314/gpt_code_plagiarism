D3DCOLOR CShaderAPIDx8::ComputeGammaCorrectedFogColor( unsigned char r, unsigned char g, unsigned char b, bool bSRGBWritesEnabled )
{
#ifdef _DEBUG
	if( g_pHardwareConfig->GetHDRType() == HDR_TYPE_FLOAT && !bSRGBWritesEnabled )
	{
//		Assert( 0 );
	}
#endif
	bool bLinearSpace =   g_pHardwareConfig->Caps().m_bFogColorAlwaysLinearSpace ||
						( bSRGBWritesEnabled && ( g_pHardwareConfig->Caps().m_bFogColorSpecifiedInLinearSpace || g_pHardwareConfig->GetHDRType() == HDR_TYPE_FLOAT ) );

	bool bScaleFogByToneMappingScale = g_pHardwareConfig->GetHDRType() == HDR_TYPE_INTEGER;

	float fr = ( r / 255.0f );
	float fg = ( g / 255.0f );
	float fb = ( b / 255.0f );
	if ( bLinearSpace )
	{
		fr = GammaToLinear( fr ); 
		fg = GammaToLinear( fg ); 
		fb = GammaToLinear( fb ); 
		if ( bScaleFogByToneMappingScale )
		{
			fr *= m_ToneMappingScale.x;		//
			fg *= m_ToneMappingScale.x;		// Linear
			fb *= m_ToneMappingScale.x;		//
		}
	}
	else if ( bScaleFogByToneMappingScale )
	{
		fr *= m_ToneMappingScale.w;			//
		fg *= m_ToneMappingScale.w;			// Gamma
		fb *= m_ToneMappingScale.w;			//
	}

	fr = MIN( fr, 1.0f );
	fg = MIN( fg, 1.0f );
	fb = MIN( fb, 1.0f );
	r = (int)( fr * 255 );
	g = (int)( fg * 255 );
	b = (int)( fb * 255 );
	return D3DCOLOR_ARGB( 255, r, g, b ); 
}