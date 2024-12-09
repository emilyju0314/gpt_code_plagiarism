void CTexture::GenerateShowMipLevelsTextures( IVTFTexture *pTexture )
{
	if( pTexture->FaceCount() > 1 )
		return;

	switch( pTexture->Format() )
	{
	// These are formats that we don't bother with for generating mip level textures.
	case IMAGE_FORMAT_RGBA16161616F:
	case IMAGE_FORMAT_R32F:
	case IMAGE_FORMAT_RGB323232F:
	case IMAGE_FORMAT_RGBA32323232F:
	case IMAGE_FORMAT_UV88:
		break;
	default:
		for (int iFrame = 0; iFrame < pTexture->FrameCount(); ++iFrame )
		{
			for (int iFace = 0; iFace < pTexture->FaceCount(); ++iFace )
			{
				for (int iMip = 0; iMip < pTexture->MipCount(); ++iMip )
				{
					int green  =	( ( iMip + 1 ) & 1 ) ? 255 : 0;
					int red	   =	( ( iMip + 1 ) & 2 ) ? 255 : 0;
					int blue   =	( ( iMip + 1 ) & 4 ) ? 255 : 0;

					int nWidth, nHeight, nDepth;
					pTexture->ComputeMipLevelDimensions( iMip, &nWidth, &nHeight, &nDepth );
					if( pTexture->Format() == IMAGE_FORMAT_DXT1  || pTexture->Format() == IMAGE_FORMAT_DXT5 ||
					    pTexture->Format() == IMAGE_FORMAT_ATI1N || pTexture->Format() == IMAGE_FORMAT_ATI2N )
					{
						unsigned char *pImageData = pTexture->ImageData( iFrame, iFace, iMip, 0, 0, 0 );
						int alpha = 255;
						FillCompressedTextureWithSingleColor( red, green, blue, alpha, pImageData, nWidth, nHeight, nDepth, pTexture->Format() );
					}
					else
					{
						for ( int z = 0; z < nDepth; ++z )
						{
							CPixelWriter pixelWriter;
							pixelWriter.SetPixelMemory( pTexture->Format(), 
								pTexture->ImageData( iFrame, iFace, iMip, 0, 0, z ), pTexture->RowSizeInBytes( iMip ) );

							for (int y = 0; y < nHeight; ++y)
							{
								pixelWriter.Seek( 0, y );
								for (int x = 0; x < nWidth; ++x)
								{
									pixelWriter.WritePixel( red, green, blue, 255 );
								}
							}
						}
					}
				}
			}
		}
		break;
	}
}