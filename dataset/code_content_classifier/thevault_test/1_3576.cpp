void CShaderAPIDx8::UnbindTexture( ShaderAPITextureHandle_t hTexture )
{
	// Make sure no texture units are currently bound to it...
	for ( int unit = 0; unit < g_pHardwareConfig->GetSamplerCount(); ++unit )
	{
		if ( hTexture == SamplerState( unit ).m_BoundTexture )
		{
			// Gotta set this here because INVALID_SHADERAPI_TEXTURE_HANDLE means don't actually
			// set bound texture (it's used for disabling texturemapping)
			SamplerState( unit ).m_BoundTexture = INVALID_SHADERAPI_TEXTURE_HANDLE;
			SetTextureState( (Sampler_t)unit, TEXTURE_BINDFLAGS_NONE, INVALID_SHADERAPI_TEXTURE_HANDLE );
		}
	}

	int nVertexSamplerCount = g_pHardwareConfig->GetVertexSamplerCount();
	for ( int nSampler = 0; nSampler < nVertexSamplerCount; ++nSampler )
	{
		if ( hTexture == m_DynamicState.m_VertexTextureState[ nSampler ].m_BoundVertexTexture )
		{
			// Gotta set this here because INVALID_SHADERAPI_TEXTURE_HANDLE means don't actually
			// set bound texture (it's used for disabling texture mapping)
			BindVertexTexture( (VertexTextureSampler_t)nSampler, INVALID_SHADERAPI_TEXTURE_HANDLE );
		}
	}
}