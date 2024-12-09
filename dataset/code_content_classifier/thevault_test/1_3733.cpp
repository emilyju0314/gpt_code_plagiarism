ITexture *CMaterialSystem::CreateNamedRenderTargetTextureEx2(
	const char *pRTName, 
	int w, 
	int h, 
	RenderTargetSizeMode_t sizeMode,	// Controls how size is generated (and regenerated on video mode change).
	ImageFormat format, 
	MaterialRenderTargetDepth_t depth,
	unsigned int textureFlags, 
	unsigned int renderTargetFlags )
{
	// Only proceed if we are between BeginRenderTargetAllocation and EndRenderTargetAllocation
	if ( !m_nAllocatingRenderTargets )
	{
		Warning( "Tried to create render target outside of CMaterialSystem::BeginRenderTargetAllocation/EndRenderTargetAllocation block\n" );
		return NULL;
	}

	ITexture* pTexture = CreateNamedRenderTargetTextureEx( pRTName, w, h, sizeMode, format, depth, textureFlags, renderTargetFlags );

	pTexture->DecrementReferenceCount(); // Follow the same convention as CTextureManager::LoadTexture (return refcount of 0).
	return pTexture;
}