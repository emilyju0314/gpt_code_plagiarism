bool CTexture::SetRenderTarget( int nRenderTargetID, ITexture *pDepthTexture )
{
	if ( ( m_nFlags & TEXTUREFLAGS_RENDERTARGET ) == 0 )
		return false;

	// Make sure we've actually allocated the texture handles
	Assert( HasBeenAllocated() );

	ShaderAPITextureHandle_t textureHandle;
	if ( !IsX360() )
	{
		textureHandle = m_pTextureHandles[0];
	}
	else
	{
		Assert( m_nFrameCount > 1 );
		textureHandle = m_pTextureHandles[m_nFrameCount-1];
	}

	ShaderAPITextureHandle_t depthTextureHandle = (ShaderAPITextureHandle_t)SHADER_RENDERTARGET_DEPTHBUFFER;

	if ( m_nFlags & TEXTUREFLAGS_DEPTHRENDERTARGET )
	{
		Assert( m_nFrameCount >= 2 );
		depthTextureHandle = m_pTextureHandles[1];
	} 
	else if ( m_nFlags & TEXTUREFLAGS_NODEPTHBUFFER )
	{
		// GR - render target without depth buffer	
		depthTextureHandle = (ShaderAPITextureHandle_t)SHADER_RENDERTARGET_NONE;
	}

	if ( pDepthTexture)
	{
		depthTextureHandle = static_cast<ITextureInternal *>(pDepthTexture)->GetTextureHandle(0);
	}

	g_pShaderAPI->SetRenderTargetEx( nRenderTargetID, textureHandle, depthTextureHandle );
	return true;
}