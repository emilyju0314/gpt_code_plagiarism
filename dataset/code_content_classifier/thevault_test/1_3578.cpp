IDirect3DSurface* CShaderAPIDx8::GetDepthTextureSurface( ShaderAPITextureHandle_t textureHandle )
{
	AssertValidTextureHandle( textureHandle );
	if ( !TextureIsAllocated( textureHandle ) )
	{
		return NULL;
	}
	return GetTexture( textureHandle ).GetDepthStencilSurface();
}