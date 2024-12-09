HRESULT CDRGTexture::CreateTexture( CImageLoader &TextureLoader, DWORD dwTextureStage, DWORD dwTextureFlags )
{
	Cleanup();

	//copy parameters into member vars
	m_pTextureLoader = &TextureLoader;
	m_pAlphaTextureLoader = NULL;	// No alpha in this case
    dwStage = dwTextureStage;
    dwFlags = dwTextureFlags;

    // Create a bitmap and load the texture file into it,
    if( FAILED( LoadTextureImage() ) )
	{
		m_pTextureLoader = NULL;
        return E_FAIL;
	}

	//
	// This may not be usable after returning from this function so set it to NULL
	//
	m_pTextureLoader = NULL;

    return S_OK;
}