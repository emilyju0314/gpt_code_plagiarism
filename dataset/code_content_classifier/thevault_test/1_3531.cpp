IImage *CSchemeManager::GetImage(const char *imageName, bool hardwareFiltered)
{
	if ( !imageName || strlen(imageName) <= 0 ) // frame icons and the like are in the scheme file and may not be defined, so if this is null then fail silently
	{
		return NULL; 
	}

	// set up to search for the bitmap
	CachedBitmapHandle_t searchBitmap;
	searchBitmap.pBitmap = NULL;

	// Prepend 'vgui/'. Resource files try to load images assuming they live in the vgui directory.
	// Used to do this in Bitmap::Bitmap, moved so that the s_pszSearchString is searching for the
	// filename with 'vgui/' already added.
	char szFileName[256];
	if ( Q_stristr( imageName, ".pic" ) )
	{
		Q_snprintf( szFileName, sizeof(szFileName), "%s", imageName );
	}
	else
	{
		Q_snprintf( szFileName, sizeof(szFileName), "vgui/%s", imageName );
	}

	s_pszSearchString = szFileName;
	int i = m_Bitmaps.Find( searchBitmap );
	if (m_Bitmaps.IsValidIndex( i ) )
	{
		return m_Bitmaps[i].pBitmap;
	}

	// couldn't find the image, try and load it
	CachedBitmapHandle_t hBitmap = { new Bitmap( szFileName, hardwareFiltered ) };
	m_Bitmaps.Insert( hBitmap );
	return hBitmap.pBitmap;
}