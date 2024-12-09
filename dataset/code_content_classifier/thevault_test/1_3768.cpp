void CTexture::FreeShaderAPITextures()
{
	if ( m_pTextureHandles && HasBeenAllocated() )
	{
		// Release the frames
		for ( int i = m_nFrameCount; --i >= 0; )
		{
			if ( g_pShaderAPI->IsTexture( m_pTextureHandles[i] ) )
			{
#ifdef WIN32
				Assert( _heapchk() == _HEAPOK );
#endif
				g_pShaderAPI->DeleteTexture( m_pTextureHandles[i] );
				m_pTextureHandles[i] = INVALID_SHADERAPI_TEXTURE_HANDLE;
			}
		}
	}
	m_nInternalFlags &= ~TEXTUREFLAGSINTERNAL_ALLOCATED;
}