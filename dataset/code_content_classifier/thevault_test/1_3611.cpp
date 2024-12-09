bool CShaderAPIDx8::SetRenderTargetInternalXbox( ShaderAPITextureHandle_t hRenderTargetTexture, bool bForce )
{
	// valid for 360 only
	if ( IsPC() )
	{
		Assert( 0 );
		return false;
	}

	if ( hRenderTargetTexture == INVALID_SHADERAPI_TEXTURE_HANDLE )
	{
		// could be a reset, force to back buffer
		hRenderTargetTexture = SHADER_RENDERTARGET_BACKBUFFER;
	}

	if ( m_hCachedRenderTarget == INVALID_SHADERAPI_TEXTURE_HANDLE )
	{
		// let the set go through to establish the initial state
		bForce = true;
	}

	if ( !bForce && ( hRenderTargetTexture == m_hCachedRenderTarget && m_DynamicState.m_bSRGBWritesEnabled == m_bUsingSRGBRenderTarget ) )
	{
		// current RT matches expected state, leave state intact
		return false;
	}

	// track the updated state
	m_bUsingSRGBRenderTarget = m_DynamicState.m_bSRGBWritesEnabled;
	m_hCachedRenderTarget = hRenderTargetTexture;

#if defined( _X360 )
	IDirect3DSurface *pSurface;
	if ( m_hCachedRenderTarget == SHADER_RENDERTARGET_BACKBUFFER )
	{
		if ( !m_bUsingSRGBRenderTarget )
		{
			pSurface = m_pBackBufferSurfaces[BACK_BUFFER_INDEX_DEFAULT];
		}
		else
		{
			pSurface = m_pBackBufferSurfaceSRGB;
		}
	}
	else
	{
		AssertValidTextureHandle( m_hCachedRenderTarget );
		Texture_t *pTexture = &GetTexture( m_hCachedRenderTarget );
	    pSurface = pTexture->GetRenderTargetSurface( m_bUsingSRGBRenderTarget );
	}

	// the 360 does a wierd reset of some states on a SetRenderTarget()
	// the viewport is a clobbered state, it may not be changed by later callers, so it MUST be put back as expected
	// the other clobbered states are waiting to be discovered ... sigh
	D3DVIEWPORT9 viewport;
	Dx9Device()->GetViewport( &viewport );
	Dx9Device()->SetRenderTarget( 0, pSurface );
	Dx9Device()->SetViewport( &viewport );
#endif

	return true;
}