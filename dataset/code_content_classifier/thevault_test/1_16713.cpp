int ReadHMMList( char *fnFormIdConfig, HMM_MODEL *&pModel, char **&pFormID, int &nModel )
{
	FILE *fp = fopen( fnFormIdConfig, "rt" );
	if( fp == NULL )
	{
		printf( "Can not open %s to read!", fnFormIdConfig );
		return -1;
	}

	// Get the number of HMM models
	char	buf[MAX_PATH];
	nModel = 0;
	while( !feof( fp ) )
	{
		if( fgets( buf, MAX_PATH, fp ) == NULL )
			break;
		if( strstr( buf, "hmm" ) == NULL )
			break;
		nModel ++;
	}
	rewind( fp );
	if( nModel == 0 )
	{
		fclose( fp );
		return -1;
	}

	// Allocate memory
	pModel = new HMM_MODEL[nModel];
	pFormID = (char**)malloc( sizeof(char*)*nModel );
	int i = 0;
	for( ; i<nModel; i++ )
		pFormID[i] = new char[MAX_PATH];

	// Read HMM models
	char	fnHMM[MAX_PATH];
	string	csDir = GetPathName( fnFormIdConfig );
	for( i=0; i<nModel; i++ )
	{
		fgets( buf, MAX_PATH, fp );

		// Remove the character RETURN at the end of the string
		buf[strlen(buf)-1] = '\0';
		if( GetPathName( buf ) == ".\\" )
			sprintf(fnHMM, "%s\\%s", (const char*)csDir.c_str(), buf);
		else
			strcpy( fnHMM, buf );
		if( ReadHMM( fnHMM, pModel[i] ) != 0 )
		{
			printf( "Read HMM model %s failed!", buf );
			return -1;
		}
		char *p = strchr( buf, '.' );
		*p = '\0';
		p = strchr( buf, '\\' );
		if( p == NULL )
			p = buf;
		else
			p++;
		strcpy( pFormID[i], buf );
	}
	fclose( fp );
	return 0;
}