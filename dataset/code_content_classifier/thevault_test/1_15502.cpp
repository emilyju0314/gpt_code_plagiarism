const char *CPLFormFilename( const char * pszPath,
                             const char * pszBasename,
                             const char * pszExtension )

{
    char *pszStaticResult = CPLGetStaticResult();
    const char  *pszAddedPathSep = "";
    const char  *pszAddedExtSep = "";

    if( pszPath == NULL )
        pszPath = "";
    else if( strlen(pszPath) > 0
             && pszPath[strlen(pszPath)-1] != '/'
             && pszPath[strlen(pszPath)-1] != '\\' )
        pszAddedPathSep = SEP_STRING;

    if( pszExtension == NULL )
        pszExtension = "";
    else if( pszExtension[0] != '.' && strlen(pszExtension) > 0 )
        pszAddedExtSep = ".";

    CPLAssert( strlen(pszPath) + strlen(pszAddedPathSep) +
               strlen(pszBasename) + strlen(pszAddedExtSep) +
               strlen(pszExtension) + 1 < CPL_PATH_BUF_SIZE );

    strncpy( pszStaticResult, pszPath, CPL_PATH_BUF_SIZE );
    strncat( pszStaticResult, pszAddedPathSep, CPL_PATH_BUF_SIZE);
    strncat( pszStaticResult, pszBasename, CPL_PATH_BUF_SIZE);
    strncat( pszStaticResult, pszAddedExtSep, CPL_PATH_BUF_SIZE);
    strncat( pszStaticResult, pszExtension, CPL_PATH_BUF_SIZE);
    pszStaticResult[CPL_PATH_BUF_SIZE - 1] = '\0';

    return pszStaticResult;
}