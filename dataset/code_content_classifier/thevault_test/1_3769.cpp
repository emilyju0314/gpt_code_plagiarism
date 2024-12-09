ImageFormat CTexture::ComputeActualFormat( ImageFormat srcFormat )
{
	ImageFormat dstFormat;
	bool bIsCompressed = ImageLoader::IsCompressed( srcFormat );
	if ( g_config.bCompressedTextures && bIsCompressed )
	{
		// for the runtime compressed formats the srcFormat won't equal the dstFormat, and we need to return srcFormat here
		if ( ImageLoader::IsRuntimeCompressed( srcFormat ) )
		{
			return srcFormat;
		}

		// don't do anything since we are already in a compressed format.
		dstFormat = g_pShaderAPI->GetNearestSupportedFormat( srcFormat );
		Assert( dstFormat == srcFormat );
		return dstFormat;
	}

	if ( IsGameConsole() && ( srcFormat == IMAGE_FORMAT_A8 ) )
	{
		// these are the right alpha formats for xbox
		return IMAGE_FORMAT_A8;
	}

#if defined( _X360 )
	if ( srcFormat == IMAGE_FORMAT_LINEAR_I8 )
	{
		return IMAGE_FORMAT_LINEAR_I8;
	}
#endif

	// NOTE: Below this piece of code is only called when compressed textures are
	// turned off, or if the source texture is not compressed.

#ifdef DX_TO_GL_ABSTRACTION
	if ( ( srcFormat == IMAGE_FORMAT_UVWQ8888 ) || ( srcFormat == IMAGE_FORMAT_UV88 ) || ( srcFormat == IMAGE_FORMAT_UVLX8888 )  )
	{
		// Danger, this is going to blow up on the Mac.  You better know what you're
		// doing with these exotic formats...which were introduced in 1999
		Assert( 0 );
	}
#endif

	// We use the TEXTUREFLAGS_EIGHTBITALPHA and TEXTUREFLAGS_ONEBITALPHA flags
	// to decide how many bits of alpha we need; vtex checks the alpha channel
	// for all white, etc.
	if( (srcFormat == IMAGE_FORMAT_UVWQ8888) || ( srcFormat == IMAGE_FORMAT_UV88 ) || 
		( srcFormat == IMAGE_FORMAT_UVLX8888 ) || ( srcFormat == IMAGE_FORMAT_RGBA16161616 ) ||
		( srcFormat == IMAGE_FORMAT_RGBA16161616F ) || ( srcFormat == IMAGE_FORMAT_RGBA32323232F ) ||
		( srcFormat == IMAGE_FORMAT_R32F ) )
	{
#ifdef DX_TO_GL_ABSTRACTION		
		dstFormat = g_pShaderAPI->GetNearestSupportedFormat( srcFormat, false );  // Stupid HACK!
#else
		dstFormat = g_pShaderAPI->GetNearestSupportedFormat( srcFormat, true );  // Stupid HACK!
#endif
	} 
	else if ( m_nFlags & ( TEXTUREFLAGS_EIGHTBITALPHA | TEXTUREFLAGS_ONEBITALPHA ) )
	{
		dstFormat = g_pShaderAPI->GetNearestSupportedFormat( IMAGE_FORMAT_BGRA8888 );
	}
	else if ( srcFormat == IMAGE_FORMAT_I8 )
	{
		dstFormat = g_pShaderAPI->GetNearestSupportedFormat( IMAGE_FORMAT_I8 );
	}
	else
	{
		dstFormat = g_pShaderAPI->GetNearestSupportedFormat( IMAGE_FORMAT_BGR888 );
	}
	return dstFormat;
}