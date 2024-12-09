void CShaderAPIDx8::SetLinearToGammaConversionTextures( ShaderAPITextureHandle_t hSRGBWriteEnabledTexture, ShaderAPITextureHandle_t hIdentityTexture )
{
	LOCK_SHADERAPI();

	m_hLinearToGammaTableTexture = hSRGBWriteEnabledTexture;
	m_hLinearToGammaTableIdentityTexture = hIdentityTexture;
}