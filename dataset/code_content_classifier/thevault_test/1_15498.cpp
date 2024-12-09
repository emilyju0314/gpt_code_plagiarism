const char *CPLGetBasename( const char *pszFullFilename )

{
    size_t  iFileStart = CPLFindFilenameStart( pszFullFilename );
    size_t  iExtStart, nLength;
    char    *pszStaticResult = CPLGetStaticResult();

    for( iExtStart = strlen(pszFullFilename);
         iExtStart > iFileStart && pszFullFilename[iExtStart] != '.';
         iExtStart-- ) {}

    if( iExtStart == iFileStart )
        iExtStart = strlen(pszFullFilename);

    nLength = iExtStart - iFileStart;

    CPLAssert( nLength < CPL_PATH_BUF_SIZE );

    strncpy( pszStaticResult, pszFullFilename + iFileStart, nLength );
    pszStaticResult[nLength] = '\0';

    return pszStaticResult;
}