void CTexture::CopyLowResImageToTexture( IVTFTexture *pTexture )
{
	int nFlags = pTexture->Flags();
	nFlags |= TEXTUREFLAGS_NOMIP | TEXTUREFLAGS_POINTSAMPLE;
	nFlags &= ~(TEXTUREFLAGS_TRILINEAR | TEXTUREFLAGS_ANISOTROPIC | TEXTUREFLAGS_HINT_DXT5);
	nFlags &= ~(TEXTUREFLAGS_NORMAL | TEXTUREFLAGS_ENVMAP);
	nFlags &= ~(TEXTUREFLAGS_ONEBITALPHA | TEXTUREFLAGS_EIGHTBITALPHA);

	Assert( pTexture->FrameCount() == 1 );

	Init( pTexture->Width(), pTexture->Height(), 1, IMAGE_FORMAT_BGR888, nFlags, 1 );
	pTexture->Init( m_LowResImageWidth, m_LowResImageHeight, 1, IMAGE_FORMAT_BGR888, nFlags, 1 );

	// Don't bother computing the actual size; it's actually equal to the low-res size
	// With only one mip level
	m_nActualWidth = m_LowResImageWidth;
	m_nActualHeight = m_LowResImageHeight;
	m_nActualDepth = 1;
	m_nActualMipCount = 1;

	// Copy the row-res image into the VTF Texture
	CPixelWriter pixelWriter;
	pixelWriter.SetPixelMemory( pTexture->Format(), 
		pTexture->ImageData( 0, 0, 0 ), pTexture->RowSizeInBytes( 0 ) );

#if !defined( _GAMECONSOLE )
	unsigned char *pLowResImage = m_pLowResImage;
#else
	unsigned char *pLowResImage = m_LowResImageSample;
#endif
	for ( int y = 0; y < m_LowResImageHeight; ++y )
	{
		pixelWriter.Seek( 0, y );
		for ( int x = 0; x < m_LowResImageWidth; ++x )
		{
			int red = pLowResImage[0];
			int green = pLowResImage[1];
			int blue = pLowResImage[2];
			pLowResImage += 3;

			pixelWriter.WritePixel( red, green, blue, 255 );
		}
	}
}