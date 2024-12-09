const char *CPLResetExtension( const char *pszPath, const char *pszExt )

{
    char    *pszStaticResult = CPLGetStaticResult();
    size_t  i;

/* -------------------------------------------------------------------- */
/*      First, try and strip off any existing extension.                */
/* -------------------------------------------------------------------- */
    strncpy( pszStaticResult, pszPath, CPL_PATH_BUF_SIZE );
    pszStaticResult[CPL_PATH_BUF_SIZE - 1] = '\0';
    for( i = strlen(pszStaticResult) - 1; i > 0; i-- )
    {
        if( pszStaticResult[i] == '.' )
        {
            pszStaticResult[i] = '\0';
            break;
        }

        if( pszStaticResult[i] == '/' || pszStaticResult[i] == '\\' 
            || pszStaticResult[i] == ':' )
            break;
    }

/* -------------------------------------------------------------------- */
/*      Append the new extension.                                       */
/* -------------------------------------------------------------------- */
    CPLAssert( strlen(pszExt) + 2 < CPL_PATH_BUF_SIZE );
    
    strcat( pszStaticResult, "." );
    strcat( pszStaticResult, pszExt );

    return pszStaticResult;
}