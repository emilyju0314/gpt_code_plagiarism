const char *CPLGetExtension( const char *pszFullFilename )

{
    size_t  iFileStart = CPLFindFilenameStart( pszFullFilename );
    size_t  iExtStart;
    char    *pszStaticResult = CPLGetStaticResult();

    for( iExtStart = strlen(pszFullFilename);
         iExtStart > iFileStart && pszFullFilename[iExtStart] != '.';
         iExtStart-- ) {}

    if( iExtStart == iFileStart )
        iExtStart = strlen(pszFullFilename)-1;

    strncpy( pszStaticResult, pszFullFilename+iExtStart+1, CPL_PATH_BUF_SIZE );
    pszStaticResult[CPL_PATH_BUF_SIZE - 1] = '\0';

    return pszStaticResult;
}