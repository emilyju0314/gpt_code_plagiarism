void ITextureInternal::ChangeRenderTarget( 
	ITextureInternal *pTex,
	int w,
	int	h,
	RenderTargetSizeMode_t sizeMode, 
	ImageFormat fmt, 
	RenderTargetType_t type, 
	unsigned int textureFlags, 
	unsigned int renderTargetFlags )
{
	pTex->Release();
	dynamic_cast< CTexture * >(pTex)->InitRenderTarget( pTex->GetName(), w, h, sizeMode, fmt, type, textureFlags, renderTargetFlags );
}