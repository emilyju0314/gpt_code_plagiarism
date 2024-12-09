ShaderAPITextureHandle_t CTexture::GetTextureHandle( int nFrame, int nTextureChannel )
{
	if ( nFrame < 0 )
	{
		nFrame = 0;
		Warning( "CTexture::GetTextureHandle(): nFrame is < 0!\n" );
	}
	if ( nFrame >= m_nFrameCount )
	{
		// NOTE: This can happen during alt-tab.  If you alt-tab while loading a level then the first local cubemap bind will do this, for example.
		Assert( nFrame < m_nFrameCount );
		return INVALID_SHADERAPI_TEXTURE_HANDLE;
	}
	Assert( nTextureChannel < 2 );

	// Make sure we've actually allocated the texture handles
	Assert( HasBeenAllocated() );
	if ( m_pTextureHandles == NULL || !HasBeenAllocated() )
	{
		return INVALID_SHADERAPI_TEXTURE_HANDLE;
	}

	return m_pTextureHandles[nFrame];
}