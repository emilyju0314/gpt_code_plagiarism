int CPLIsFilenameRelative( const char *pszFilename )

{
    if( (strlen(pszFilename) > 2
         && (strncmp(pszFilename+1,":\\",2) == 0
             || strncmp(pszFilename+1,":/",2) == 0))
        || pszFilename[0] == '\\'
        || pszFilename[0] == '/' )
        return FALSE;
    else
        return TRUE;
}