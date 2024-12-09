void CMatLightmaps::BumpedLightmapBitsToPixelWriter_LDR( float* pFloatImage, float *pFloatImageBump1, float *pFloatImageBump2, 
	float *pFloatImageBump3, int pLightmapSize[2], int pOffsetIntoLightmapPage[2], FloatBitMap_t *pfmOut )
{
	const int nLightmapSize0 = pLightmapSize[0];
	const int nLightmap0WriterSizeBytes = nLightmapSize0 * m_LightmapPixelWriter.GetPixelSize();
	const int nRewindToNextPixel = -( ( nLightmap0WriterSizeBytes * 3 ) - m_LightmapPixelWriter.GetPixelSize() );

	for( int t = 0; t < pLightmapSize[1]; t++ )
	{
		int srcTexelOffset = ( sizeof( Vector4D ) / sizeof( float ) ) * ( 0 + t * nLightmapSize0 );
		m_LightmapPixelWriter.Seek( pOffsetIntoLightmapPage[0], pOffsetIntoLightmapPage[1] + t );

		for( int s = 0; s < nLightmapSize0; 
			s++, m_LightmapPixelWriter.SkipBytes(nRewindToNextPixel),srcTexelOffset += (sizeof(Vector4D)/sizeof(float)))
		{
			unsigned char color[4][4];

			ColorSpace::LinearToBumpedLightmap( &pFloatImage[srcTexelOffset],
				&pFloatImageBump1[srcTexelOffset], &pFloatImageBump2[srcTexelOffset],
				&pFloatImageBump3[srcTexelOffset],
				color[0], color[1], color[2], color[3] );

			if ( HardwareConfig()->GetCSMAccurateBlending() )
			{
				ColorSpace::LinearToBumpedLightmapAlpha( &pFloatImage[srcTexelOffset + 3], 
														 &pFloatImageBump1[srcTexelOffset + 3], &pFloatImageBump2[srcTexelOffset + 3], &pFloatImageBump3[srcTexelOffset + 3],
														 &color[0][3], &color[1][3], &color[2][3], &color[3][3] );
			}
			else
			{
				unsigned char alpha =  RoundFloatToByte( pFloatImage[srcTexelOffset+3] * 255.0f );
				color[0][3] = alpha;
				color[1][3] = alpha;
				color[2][3] = alpha;
				color[3][3] = alpha;
			}

			m_LightmapPixelWriter.WritePixelNoAdvance( color[0][0], color[0][1], color[0][2], color[0][3] );

			m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
			m_LightmapPixelWriter.WritePixelNoAdvance( color[1][0], color[1][1], color[1][2], color[1][3] );

			m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
			m_LightmapPixelWriter.WritePixelNoAdvance( color[2][0], color[2][1], color[2][2], color[2][3] );

			m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
			m_LightmapPixelWriter.WritePixelNoAdvance( color[3][0], color[3][1], color[3][2], color[3][3] );
		}
	}
	if ( pfmOut )
	{
		for( int t = 0; t < pLightmapSize[1]; t++ )
		{
			int srcTexelOffset = ( sizeof( Vector4D ) / sizeof( float ) ) * ( 0 + t * nLightmapSize0 );
			for( int s = 0;  s < nLightmapSize0; s++,srcTexelOffset += (sizeof(Vector4D)/sizeof(float)))
			{
				unsigned char color[4][4];

				ColorSpace::LinearToBumpedLightmap( &pFloatImage[srcTexelOffset],
					&pFloatImageBump1[srcTexelOffset], &pFloatImageBump2[srcTexelOffset],
					&pFloatImageBump3[srcTexelOffset],
					color[0], color[1], color[2], color[3] );

				unsigned char alpha =  RoundFloatToByte( pFloatImage[srcTexelOffset+3] * 255.0f );
				// Write data to the bitmapped represenations so that PFM files can be written
				PixRGBAF pixelData;
				pixelData.Red = color[0][0];                  
				pixelData.Green = color[0][1];                  
				pixelData.Blue = color[0][2];
				pixelData.Alpha = alpha;
				pfmOut->WritePixelRGBAF( pOffsetIntoLightmapPage[0] + s, pOffsetIntoLightmapPage[1] + t, 0, pixelData);
			}
		}

	}
}