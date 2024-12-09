const char *CPLProjectRelativeFilename( const char *pszProjectDir, 
                                        const char *pszSecondaryFilename )

{
    char *pszStaticResult = CPLGetStaticResult();

    if( !CPLIsFilenameRelative( pszSecondaryFilename ) )
        return pszSecondaryFilename;

    if( pszProjectDir == NULL || strlen(pszProjectDir) == 0 )
        return pszSecondaryFilename;

    strncpy( pszStaticResult, pszProjectDir, CPL_PATH_BUF_SIZE );
    pszStaticResult[CPL_PATH_BUF_SIZE - 1] = '\0';

    if( pszProjectDir[strlen(pszProjectDir)-1] != '/' 
        && pszProjectDir[strlen(pszProjectDir)-1] != '\\' )
    {
        CPLAssert( strlen(SEP_STRING) + 1 < CPL_PATH_BUF_SIZE );

        strcat( pszStaticResult, SEP_STRING );
    }

    CPLAssert( strlen(pszSecondaryFilename) + 1 < CPL_PATH_BUF_SIZE );

    strcat( pszStaticResult, pszSecondaryFilename );
        
    return pszStaticResult;
}