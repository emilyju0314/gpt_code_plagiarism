IDirect3DSurface* CShaderAPIDx8::GetTextureSurface( ShaderAPITextureHandle_t textureHandle )
{
	MEM_ALLOC_D3D_CREDIT();

	IDirect3DSurface* pSurface;

	// We'll be modifying this sucka
	AssertValidTextureHandle( textureHandle );

	//APSFIXME
	//tmauer
	//right now the 360 is getting invalid texture hadles here
	// <sergiy> 5/20/2015: There's significant number of crashes in Windows NT - Crash Reports for CShaderAPIDx8::ReadPixelsAsync(int, int, int, int, unsigned char*, ImageFormat, ITexture*, CThreadEvent*)
	//                     due to this handle being invalid. It may have to do with losing D3D device. Robustifying this code to check if the crashes will end.
	if ( !m_Textures.IsValidIndex( textureHandle ) )
	{
		return NULL;
	}

	Texture_t &tex = GetTexture( textureHandle );
	if ( !( tex.m_Flags & Texture_t::IS_ALLOCATED ) )
	{
		return NULL;
	}

	if ( IsX360() && ( tex.m_Flags & Texture_t::IS_RENDER_TARGET_SURFACE ) )
	{
		pSurface = tex.GetRenderTargetSurface( false );
		pSurface->AddRef();
		return pSurface;
	}

	IDirect3DBaseTexture* pD3DTex = CShaderAPIDx8::GetD3DTexture( textureHandle );
	IDirect3DTexture* pTex = static_cast<IDirect3DTexture*>( pD3DTex );
	Assert( pTex );
	if ( !pTex )
	{
		return NULL;
	}
	
	HRESULT hr = pTex->GetSurfaceLevel( 0, &pSurface );
	Assert( hr == D3D_OK );

	return pSurface;
}