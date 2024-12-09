bool CTexture::SetupDebuggingTextures( IVTFTexture *pVTFTexture )
{
	if ( IsGameConsole() )
	{
		// not supporting
		return false;
	}

	if ( pVTFTexture->Flags() & TEXTUREFLAGS_NODEBUGOVERRIDE )
		return false;

	if ( g_config.bDrawGray )
	{
		GenerateGrayTexture( pVTFTexture );
		return true;
	}

	if ( g_config.nShowMipLevels )
	{
		// mat_showmiplevels 1 means don't do normal maps
		if ( ( g_config.nShowMipLevels == 1 ) && ( pVTFTexture->Flags() & ( TEXTUREFLAGS_NORMAL | TEXTUREFLAGS_SSBUMP ) ) )
			return false;

		// mat_showmiplevels 2 means don't do base textures
		if ( ( g_config.nShowMipLevels == 2 ) && !( pVTFTexture->Flags() & ( TEXTUREFLAGS_NORMAL | TEXTUREFLAGS_SSBUMP ) ) )
			return false;

		// This mode shows the mip levels as different colors
		GenerateShowMipLevelsTextures( pVTFTexture );
		return true;
	}
	else if ( g_config.bShowLowResImage && pVTFTexture->FrameCount() == 1 && 
		pVTFTexture->FaceCount() == 1 && ((pVTFTexture->Flags() & TEXTUREFLAGS_NORMAL) == 0) &&
		m_LowResImageWidth != 0 && m_LowResImageHeight != 0 )
	{
		// This mode just uses the low res texture
		CopyLowResImageToTexture( pVTFTexture );
		return true;
	}

	return false;
}