void V_SetExtension( char *path, const char *extension, int pathStringLength )
{
	V_StripExtension( path, path, pathStringLength );

	// This fails if the filename has multiple extensions (i.e. "filename.360.vtex_c").
	//V_DefaultExtension( path, extension, pathStringLength );

	// Concatenate the desired extension
	char pTemp[MAX_PATH];
	if ( extension[0] != '.' )
	{
		pTemp[0] = '.';
		V_strncpy( &pTemp[1], extension, sizeof(pTemp) - 1 );
		extension = pTemp;
	}
	V_strncat( path, extension, pathStringLength, COPY_ALL_CHARACTERS );
}