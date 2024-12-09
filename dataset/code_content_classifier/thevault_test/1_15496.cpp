const char *CPLGetDirname( const char *pszFilename )

{
    int         iFileStart = CPLFindFilenameStart(pszFilename);
    char       *pszStaticResult = CPLGetStaticResult();

    CPLAssert( iFileStart < CPL_PATH_BUF_SIZE );

    if( iFileStart == 0 )
    {
        strcpy( pszStaticResult, "." );
        return pszStaticResult;
    }

    strncpy( pszStaticResult, pszFilename, iFileStart );
    pszStaticResult[iFileStart] = '\0';

    if( iFileStart > 1
        && (pszStaticResult[iFileStart-1] == '/'
            || pszStaticResult[iFileStart-1] == '\\') )
        pszStaticResult[iFileStart-1] = '\0';

    return pszStaticResult;
}