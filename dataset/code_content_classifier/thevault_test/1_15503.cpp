const char *CPLFormCIFilename( const char * pszPath,
                               const char * pszBasename,
                               const char * pszExtension )

{
#if defined(WIN32) || defined(WIN32CE)
    return CPLFormFilename( pszPath, pszBasename, pszExtension );
#else
    const char  *pszAddedExtSep = "";
    char        *pszFilename;
    const char  *pszFullPath;
    int         nLen = strlen(pszBasename)+2, i;
    FILE        *fp;

    if( pszExtension != NULL )
        nLen += strlen(pszExtension);

    pszFilename = (char *) CPLMalloc(nLen);

    if( pszExtension == NULL )
        pszExtension = "";
    else if( pszExtension[0] != '.' && strlen(pszExtension) > 0 )
        pszAddedExtSep = ".";

    sprintf( pszFilename, "%s%s%s", 
             pszBasename, pszAddedExtSep, pszExtension );

    pszFullPath = CPLFormFilename( pszPath, pszFilename, NULL );
    fp = VSIFOpen( pszFullPath, "r" );
    if( fp == NULL )
    {
        for( i = 0; pszFilename[i] != '\0'; i++ )
        {
            if( islower(pszFilename[i]) )
                pszFilename[i] = toupper(pszFilename[i]);
        }

        pszFullPath = CPLFormFilename( pszPath, pszFilename, NULL );
        fp = VSIFOpen( pszFullPath, "r" );
    }

    if( fp == NULL )
    {
        for( i = 0; pszFilename[i] != '\0'; i++ )
        {
            if( isupper(pszFilename[i]) )
                pszFilename[i] = tolower(pszFilename[i]);
        }

        pszFullPath = CPLFormFilename( pszPath, pszFilename, NULL );
        fp = VSIFOpen( pszFullPath, "r" );
    }

    if( fp != NULL )
        VSIFClose( fp );
    else
        pszFullPath = CPLFormFilename( pszPath, pszBasename, pszExtension );

    CPLFree( pszFilename );

    return pszFullPath;
#endif
}