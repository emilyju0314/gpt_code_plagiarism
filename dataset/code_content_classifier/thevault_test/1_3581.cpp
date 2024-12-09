void CShaderAPIDx8::TexSubImage2D( 
	int			level, 
	int			cubeFaceID,
	int			xOffset,
	int			yOffset, 
	int			zOffset,
	int			width,
	int			height,
	ImageFormat srcFormat,
	int			srcStride,
	bool		bSrcIsTiled,
	void		*pSrcData )
{
	LOCK_SHADERAPI();

	Assert( pSrcData );
	AssertValidTextureHandle( GetModifyTextureHandle() );

	if ( !m_Textures.IsValidIndex( GetModifyTextureHandle() ) )
		return;

	// NOTE: This can only be done with procedural textures if this method is
	// being used to download the entire texture, cause last frame's partial update
	// may be in a completely different texture! Sadly, I don't have all of the
	// information I need, but I can at least check a couple things....
#ifdef _DEBUG
	if ( GetTexture( GetModifyTextureHandle() ).m_NumCopies > 1 )
	{
		Assert( (xOffset == 0) && (yOffset == 0) );
	}
#endif

	// This test here just makes sure we don't try to download mipmap levels
	// if we weren't able to create them in the first place
	Texture_t& tex = GetTexture( GetModifyTextureHandle() );
	if ( level >= tex.m_NumLevels )
	{
		return;
	}

	// May need to switch textures....
	if ( tex.m_SwitchNeeded )
	{
		AdvanceCurrentCopy( GetModifyTextureHandle() );
		tex.m_SwitchNeeded = false;
	}

	TextureLoadInfo_t info;
	info.m_TextureHandle = GetModifyTextureHandle();
	info.m_pTexture = GetModifyTexture();
	info.m_nLevel = level;
	info.m_nCopy = tex.m_CurrentCopy;
	info.m_CubeFaceID = (D3DCUBEMAP_FACES)cubeFaceID;
	info.m_nWidth = width;
	info.m_nHeight = height;
	info.m_nZOffset = zOffset;
	info.m_SrcFormat = srcFormat;
	info.m_pSrcData = (unsigned char *)pSrcData;
#if defined( _X360 )
	info.m_bSrcIsTiled = bSrcIsTiled;
	info.m_bCanConvertFormat = ( tex.m_Flags & Texture_t::CAN_CONVERT_FORMAT ) != 0;
#endif
	LoadSubTexture( info, xOffset, yOffset, srcStride );
}