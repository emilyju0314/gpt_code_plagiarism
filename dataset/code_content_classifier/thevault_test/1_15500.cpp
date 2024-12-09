char *CPLGetCurrentDir()

{
    size_t  nPathMax;
    char    *pszDirPath;

# ifdef _MAX_PATH
    nPathMax = _MAX_PATH;
# elif PATH_MAX
    nPathMax = PATH_MAX;
# else
    nPathMax = 8192;
# endif

    pszDirPath = (char*)CPLMalloc( nPathMax );
    if ( !pszDirPath )
        return NULL;

#ifdef HAVE_GETCWD
    return getcwd( pszDirPath, nPathMax );
#else
    return NULL;
#endif /* HAVE_GETCWD */
}