void CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRF( float* pFloatImage, float *pFloatImageBump1, float *pFloatImageBump2, 
												 float *pFloatImageBump3, int pLightmapSize[2], int pOffsetIntoLightmapPage[2], FloatBitMap_t *pfmOut )
{
	if ( IsX360() )
	{
		// 360 does not support HDR float mode 
		Assert( 0 );
		return;
	}

	Assert( !pfmOut );		// unsupported in this mode

	const int nLightmapSize0 = pLightmapSize[0];
	const int nLightmap0WriterSizeBytes = nLightmapSize0 * m_LightmapPixelWriter.GetPixelSize();
	const int nRewindToNextPixel = -( ( nLightmap0WriterSizeBytes * 3 ) - m_LightmapPixelWriter.GetPixelSize() );

	for( int t = 0; t < pLightmapSize[1]; t++ )
	{
		int srcTexelOffset = ( sizeof( Vector4D ) / sizeof( float ) ) * ( 0 + t * nLightmapSize0 );
		m_LightmapPixelWriter.Seek( pOffsetIntoLightmapPage[0], pOffsetIntoLightmapPage[1] + t );

		// if it's anything but 4 x float16 on a PPC...
 		/*
		// The 'else' path uses ConvertFourFloatsTo16BitsAtOnce which is entirely broken
		// so we need to always use the main path.
		if ( !IsGameConsole() ||
 			 !(m_LightmapPixelWriter.GetPixelSize() == 4*sizeof(unsigned short)) ||
 			 !(m_LightmapPixelWriter.IsUsing16BitFloatFormat())						
			 )*/
		{
			for( int s = 0; 
				s < nLightmapSize0; 
				s++, m_LightmapPixelWriter.SkipBytes(nRewindToNextPixel),srcTexelOffset += (sizeof(Vector4D)/sizeof(float)))
			{
				float color[4][4];

				// [mariod] - LinearToBumpedLightmap() was entirely missing in the float path as of September '11
				// looks like this only affected PS3 (PC/X360 use linear 16bit tex formats)
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
					float alpha = pFloatImage[srcTexelOffset+3];
					color[0][3] = alpha;
					color[1][3] = alpha;
					color[2][3] = alpha;
					color[3][3] = alpha;
				}

				m_LightmapPixelWriter.WritePixelNoAdvanceF( color[0][0], color[0][1], color[0][2], color[0][3] );

				m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
				m_LightmapPixelWriter.WritePixelNoAdvanceF( color[1][0], color[1][1], color[1][2], color[1][3] );

				m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
				m_LightmapPixelWriter.WritePixelNoAdvanceF( color[2][0], color[2][1], color[2][2], color[2][3] );

				m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
				m_LightmapPixelWriter.WritePixelNoAdvanceF( color[3][0], color[3][1], color[3][2], color[3][3] );
			}
		}
		/*
		else // use a faster technique on PPC cores for float16 lightmaps, that's not so branchy and load-hit-store-y
		{
			for( int s = 0; 
				s < nLightmapSize0; 
				s++, m_LightmapPixelWriter.SkipBytes(nRewindToNextPixel),srcTexelOffset += (sizeof(Vector4D)/sizeof(float)))
			{

				float color[4][4];

				// [mariod] - LinearToBumpedLightmap() was entirely missing in the float path as of September '11
				// looks like this only affected PS3 (PC/X360 use linear 16bit tex formats)
				ColorSpace::LinearToBumpedLightmap( &pFloatImage[srcTexelOffset],
					&pFloatImageBump1[srcTexelOffset], &pFloatImageBump2[srcTexelOffset],
					&pFloatImageBump3[srcTexelOffset],
					color[0], color[1], color[2], color[3] );

				float alpha = pFloatImage[srcTexelOffset+3];

				float16::ConvertFourFloatsTo16BitsAtOnce( (float16*) m_LightmapPixelWriter.GetCurrentPixel(),
					&color[0][0], &color[0][1], &color[0][2], &alpha );

				m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
				float16::ConvertFourFloatsTo16BitsAtOnce( (float16*) m_LightmapPixelWriter.GetCurrentPixel(),
					&color[1][0], &color[1][1], &color[1][2], &alpha );

				m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
				float16::ConvertFourFloatsTo16BitsAtOnce( (float16*) m_LightmapPixelWriter.GetCurrentPixel(),
					&color[2][0], &color[2][1], &color[2][2], &alpha );

				m_LightmapPixelWriter.SkipBytes( nLightmap0WriterSizeBytes );
				float16::ConvertFourFloatsTo16BitsAtOnce( (float16*) m_LightmapPixelWriter.GetCurrentPixel(),
					&color[3][0], &color[3][1], &color[3][2], &alpha );
			}
		}
		*/
	}
}