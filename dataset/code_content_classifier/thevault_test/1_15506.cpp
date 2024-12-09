const char *CPLExtractRelativePath( const char *pszBaseDir, 
                                    const char *pszTarget,
                                    int *pbGotRelative )

{
    size_t nBasePathLen;

/* -------------------------------------------------------------------- */
/*      If we don't have a basedir, then we can't relativize the path.  */
/* -------------------------------------------------------------------- */
    if( pszBaseDir == NULL )
    {
        if( pbGotRelative != NULL )
            *pbGotRelative = FALSE;

        return pszTarget;
    }

    nBasePathLen = strlen(pszBaseDir);

/* -------------------------------------------------------------------- */
/*      One simple case is where neither file has a path.  We return    */
/*      the original target filename and it is relative.                */
/* -------------------------------------------------------------------- */
    const char *pszTargetPath = CPLGetPath(pszTarget);

    if( (nBasePathLen == 0 || EQUAL(pszBaseDir,"."))
        && (strlen(pszTargetPath) == 0 || EQUAL(pszTargetPath,".")) )
    {
        if( pbGotRelative != NULL )
            *pbGotRelative = TRUE;

        return pszTarget;
    }

/* -------------------------------------------------------------------- */
/*      By this point, if we don't have a base path, we can't have a    */
/*      meaningful common prefix.                                       */
/* -------------------------------------------------------------------- */
    if( nBasePathLen == 0 )
    {
        if( pbGotRelative != NULL )
            *pbGotRelative = FALSE;

        return pszTarget;
    }

/* -------------------------------------------------------------------- */
/*      If we don't have a common path prefix, then we can't get a      */
/*      relative path.                                                  */
/* -------------------------------------------------------------------- */
    if( !EQUALN(pszBaseDir,pszTarget,nBasePathLen) 
        || (pszTarget[nBasePathLen] != '\\' 
            && pszTarget[nBasePathLen] != '/') )
    {
        if( pbGotRelative != NULL )
            *pbGotRelative = FALSE;

        return pszTarget;
    }

/* -------------------------------------------------------------------- */
/*      We have a relative path.  Strip it off to get a string to       */
/*      return.                                                         */
/* -------------------------------------------------------------------- */
    if( pbGotRelative != NULL )
        *pbGotRelative = TRUE;

    return pszTarget + nBasePathLen + 1;
}