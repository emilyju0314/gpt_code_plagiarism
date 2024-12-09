int CTexture::ComputeActualMipCount() const
{
	bool bForceTextureAllMips = g_bForceTextureAllMips; // Init with global set from -forceallmips on the command line

	// If the current hardware doesn't support mipped cubemaps, return 1
	if ( ( m_nFlags & TEXTUREFLAGS_ENVMAP ) && ( !HardwareConfig()->SupportsMipmappedCubemaps() ) )
	{
		return 1;
	}

	// "nomip 1" - If the artists requested no mips in the .txt file of their source art, return 1
	if ( m_nFlags & TEXTUREFLAGS_NOMIP )
	{
		return 1;
	}

	// "allmips 1" - If the artists requested all mips in the .txt file of their source art, load all mips on all platforms
	if ( m_nFlags & TEXTUREFLAGS_ALL_MIPS )
	{
		bForceTextureAllMips = true;
	}

	// "mostmips 1" - If the artists requested most mips in the .txt file of their source art, don't load the bottom mips, ever
	bool bMostMips = false;
	if ( m_nFlags & TEXTUREFLAGS_MOST_MIPS )
	{
		bMostMips = true;
	}

	// OpenGL - Don't ever drop mips
	if ( IsOpenGL() )
	{
		bForceTextureAllMips = true;
		bMostMips = false;
	}

	// If on the PC and running a newer OS than WinXP, then don't drop mips.
	// XP can crash if we run out of paged pool memory since each mip consumes ~1kb of paged pool memory.
	#if defined( WIN32 ) && !defined( _GAMECONSOLE )
	{
		OSVERSIONINFOEX osvi;
		ZeroMemory( &osvi, sizeof( OSVERSIONINFOEX ) );
		osvi.dwOSVersionInfoSize = sizeof( OSVERSIONINFOEX );
		if ( GetVersionEx( ( OSVERSIONINFO * )&osvi ) )
		{
			if ( osvi.dwMajorVersion >= 6 ) // Major version 6 is Windows Vista and Win7
			{
				// Windows Vista or newer, so it's safe to load all mips
				bForceTextureAllMips = true;
			}
		}
	}
	#endif

	if ( IsX360() )
	{
		bForceTextureAllMips  = true;
	}

	bool bIsFlashlightTextureOnGL = false;
#ifdef DX_TO_GL_ABSTRACTION
	 // Hack to only recognize the border bit (for the purposes of truncating the mip chain) on "flashlight" textures on Mac
	const char *pTexName = m_Name.String();
	bIsFlashlightTextureOnGL =  ( m_nFlags & TEXTUREFLAGS_BORDER ) && V_stristr( pTexName, "flashlight" );
#endif
	
	// If we are not loading all mips, then count the number of mips we want to load
	if ( ( !IsOpenGL() && !bForceTextureAllMips ) || bMostMips || bIsFlashlightTextureOnGL )
	{
		// Stop loading mips when width or height is < 32
		int nMaxMipSize = 32; // Default for windows XP
		if ( IsPS3() )
		{
			nMaxMipSize = 4;
		}

		if ( bMostMips )
		{
			// !!! This overrides all other settings !!!
			nMaxMipSize = 32;
		}

		int nNumMipLevels = 1;
		int h = m_nActualWidth;
		int w = m_nActualHeight;
		while (	MIN( w, h ) > nMaxMipSize )
		{
			nNumMipLevels++;
			
			w >>= 1;
			h >>= 1;
		}
		return nNumMipLevels;
	}
	else
	{
		// Load all mips
		return ImageLoader::GetNumMipMapLevels( m_nActualWidth, m_nActualHeight, m_nActualDepth );
	}
}