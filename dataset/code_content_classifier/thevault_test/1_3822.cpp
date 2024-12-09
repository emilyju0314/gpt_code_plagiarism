const char *V_GetFileExtension( const char *path )
{
	int len = V_strlen( path );
	if ( len <= 1 )
		return NULL;

	const char *src = path + len - 1;

	//
	// back up until a . or the start
	//
	while (src != path && *(src-1) != '.' )
		src--;

	// check to see if the '.' is part of a pathname
	if (src == path || PATHSEPARATOR( *src ) )
	{		
		return NULL;  // no extension
	}

	return src;
}