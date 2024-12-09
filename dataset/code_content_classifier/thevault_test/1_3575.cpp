void CShaderAPIDx8::ComputeStatsInfo( ShaderAPITextureHandle_t hTexture, bool bIsCubeMap, bool isVolumeTexture )
{
	Texture_t &textureData = GetTexture( hTexture );

	textureData.m_SizeBytes = 0;
	textureData.m_SizeTexels = 0;
	textureData.m_LastBoundFrame = -1;
	if ( IsX360() )
	{
		textureData.m_nTimesBoundThisFrame = 0;
	}

	IDirect3DBaseTexture* pD3DTex = CShaderAPIDx8::GetD3DTexture( hTexture );

	if ( IsPC() || !IsX360() )
	{
		if ( bIsCubeMap )
		{
			IDirect3DCubeTexture* pTex = static_cast<IDirect3DCubeTexture*>(pD3DTex);
			if ( !pTex )
			{
				Assert( 0 );
				return;
			}

			int numLevels = pTex->GetLevelCount();
			for (int i = 0; i < numLevels; ++i)
			{
				D3DSURFACE_DESC desc;
				HRESULT hr = pTex->GetLevelDesc( i, &desc );
				Assert( !FAILED(hr) );
				textureData.m_SizeBytes += 6 * ImageLoader::GetMemRequired( desc.Width, desc.Height, 1, textureData.GetImageFormat(), false );
				textureData.m_SizeTexels += 6 * desc.Width * desc.Height;
			}
		}
		else if ( isVolumeTexture )
		{
			IDirect3DVolumeTexture9* pTex = static_cast<IDirect3DVolumeTexture9*>(pD3DTex);
			if ( !pTex )
			{
				Assert( 0 );
				return;
			}
			int numLevels = pTex->GetLevelCount();
			for (int i = 0; i < numLevels; ++i)
			{
				D3DVOLUME_DESC desc;
				HRESULT hr = pTex->GetLevelDesc( i, &desc );
				Assert( !FAILED( hr ) );
				textureData.m_SizeBytes += ImageLoader::GetMemRequired( desc.Width, desc.Height, desc.Depth, textureData.GetImageFormat(), false );
				textureData.m_SizeTexels += desc.Width * desc.Height;
			}
		}
		else
		{
			IDirect3DTexture* pTex = static_cast<IDirect3DTexture*>(pD3DTex);
			if ( !pTex )
			{
				Assert( 0 );
				return;
			}

			int numLevels = pTex->GetLevelCount();
			for (int i = 0; i < numLevels; ++i)
			{
				D3DSURFACE_DESC desc;
				HRESULT hr = pTex->GetLevelDesc( i, &desc );
				Assert( !FAILED( hr ) );
				textureData.m_SizeBytes += ImageLoader::GetMemRequired( desc.Width, desc.Height, 1, textureData.GetImageFormat(), false );
				textureData.m_SizeTexels += desc.Width * desc.Height;
			}
		}
	}

#if defined( _X360 )
	// 360 uses gpu storage size (which accounts for page alignment bloat), not format size
	textureData.m_SizeBytes = g_TextureHeap.GetSize( pD3DTex );
#endif
}