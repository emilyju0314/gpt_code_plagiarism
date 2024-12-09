inline IDirect3DBaseTexture* CShaderAPIDx8::GetD3DTexture( ShaderAPITextureHandle_t hTexture )
{
	if ( hTexture == INVALID_SHADERAPI_TEXTURE_HANDLE )
	{
		return NULL;
	}

	AssertValidTextureHandle( hTexture );

	Texture_t& tex = GetTexture( hTexture );
	if ( tex.m_NumCopies == 1 )
	{
		return tex.GetTexture();
	}
	else
	{
		return tex.GetTexture( tex.m_CurrentCopy );
	}
}