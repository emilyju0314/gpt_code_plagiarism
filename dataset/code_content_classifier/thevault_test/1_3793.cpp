void LoadSubTexture( TextureLoadInfo_t &info, int xOffset, int yOffset, int srcStride )
{
	Assert( info.m_pSrcData );
	Assert( info.m_pTexture );

#if defined( _X360 )
	// xboxissue - not supporting subrect swizzling
	Assert( !info.m_bSrcIsTiled );
#endif

#ifdef _DEBUG
	ImageFormat format = GetImageFormat( info.m_pTexture );
	Assert( (format == ImageLoader::D3DFormatToImageFormat( FindNearestSupportedFormat(format, false, false, false )) ) && (format != -1) );
#endif

	// Copy in the bits...
	BlitTextureBits( info, xOffset, yOffset, srcStride );
}