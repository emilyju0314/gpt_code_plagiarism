const char *CPLGetFilename( const char *pszFullFilename )

{
    int iFileStart = CPLFindFilenameStart( pszFullFilename );
    char       *pszStaticResult = CPLGetStaticResult();

    strncpy( pszStaticResult, pszFullFilename + iFileStart, 
             CPL_PATH_BUF_SIZE );
    pszStaticResult[CPL_PATH_BUF_SIZE - 1] = '\0';

    return pszStaticResult;
}