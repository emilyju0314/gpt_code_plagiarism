HRESULT CDRGTexture::LoadTextureImage()
{

	//
	// Load the Texture
	//
	if( m_pTextureLoader )
	{
		HBITMAP *pAlpha = NULL;
		if( !m_pAlphaTextureLoader )
			pAlpha = &hbmAlphaBitmap;
		if( FAILED( m_pTextureLoader->LoadImage( &hbmBitmap, pAlpha ) ) )
			return DDERR_NOTFOUND;
		if( hbmBitmap == NULL )
			return DDERR_NOTFOUND;
		if( hbmAlphaBitmap )
			bHasAlpha = TRUE;
	}
	
	if( bHasAlpha && m_pAlphaTextureLoader && !hbmAlphaBitmap )
	{
		if( FAILED( m_pAlphaTextureLoader->LoadImage( &hbmAlphaBitmap, NULL ) ) )
			return DDERR_NOTFOUND;
		if( hbmAlphaBitmap == NULL )
			return DDERR_NOTFOUND;
	}

	//last sanity check.
	if (hbmBitmap)
	{
		if (bHasAlpha)
		{
			if (hbmAlphaBitmap)
				return DD_OK; // alpha and bitmap found
			else
			{
				//
				// Free the loaded Bitmap
				//
				DeleteObject( hbmBitmap );
				hbmBitmap = NULL;
				return DDERR_NOTFOUND; //asked for alpha, but alpha not found
			}
		}
		else
			return DD_OK; //no alpha, bitmap found
	}
	else if( hbmAlphaBitmap )
	{
		DeleteObject( hbmAlphaBitmap );
		hbmAlphaBitmap = NULL;
	}

	return DDERR_NOTFOUND; //bitmap couldn't load
}