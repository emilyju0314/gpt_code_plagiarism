void CShaderAPIDx8::ModifyTexture( ShaderAPITextureHandle_t textureHandle )
{
	LOCK_SHADERAPI();
	// Can't do this if we're locked!
	Assert( m_ModifyTextureLockedLevel < 0 );

	AssertValidTextureHandle( textureHandle );
	m_ModifyTextureHandle = textureHandle;
	
	// If we're got a multi-copy texture, we need to up the current copy count
	Texture_t& tex = GetTexture( textureHandle );
	if (tex.m_NumCopies > 1)
	{
		// Each time we modify a texture, we'll want to switch texture
		// as soon as a TexImage2D call is made...
		tex.m_SwitchNeeded = true;
	}
}