void CShaderAPIDx8::SetFullScreenTextureHandle( ShaderAPITextureHandle_t h )
{
	LOCK_SHADERAPI();
	m_hFullScreenTexture = h;
}