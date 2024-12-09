void CTexture::AllocateTextureHandles()
{
	Assert( !m_pTextureHandles );

	if ( m_nFrameCount <= 0 )
	{
		AssertMsg( false, "CTexture::AllocateTextureHandles attempted to allocate 0 frames of texture handles!" );
		Warning( "CTexture::AllocateTextureHandles \"%s\" attempted to allocate 0 frames of texture handles!", GetName() );
		m_nFrameCount = 1;
	}

	m_pTextureHandles = new ShaderAPITextureHandle_t[m_nFrameCount];

	if ( m_pTextureHandles == NULL )
	{
		MemOutOfMemory( sizeof(ShaderAPITextureHandle_t) * m_nFrameCount );
	}
	else
	{
		for( int i = 0; i != m_nFrameCount; ++i )
		{
			m_pTextureHandles[i] = INVALID_SHADERAPI_TEXTURE_HANDLE;
		}
	}
}