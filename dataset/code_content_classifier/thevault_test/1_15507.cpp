const char *CPLCleanTrailingSlash( const char *pszFilename )

{
    char       *pszStaticResult = CPLGetStaticResult();
    int        iPathLength = strlen(pszFilename);

    strncpy( pszStaticResult, pszFilename, iPathLength );
    pszStaticResult[iPathLength] = '\0';

    if( iPathLength > 0 
        && (pszStaticResult[iPathLength-1] == '\\' 
            || pszStaticResult[iPathLength-1] == '/'))
        pszStaticResult[iPathLength-1] = '\0';

    return pszStaticResult;
}