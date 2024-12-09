void *CPLGetSymbol( const char * pszLibrary, const char * pszSymbolName )

{
    void        *pLibrary;
    void        *pSymbol;

    pLibrary = dlopen(pszLibrary, RTLD_LAZY);
    if( pLibrary == NULL )
    {
        CPLError( CE_Failure, CPLE_AppDefined,
                  "%s", dlerror() );
        return NULL;
    }

    pSymbol = dlsym( pLibrary, pszSymbolName );

#if (defined(__APPLE__) && defined(__MACH__))
    /* On mach-o systems, C symbols have a leading underscore and depending
     * on how dlcompat is configured it may or may not add the leading
     * underscore.  So if dlsym() fails add an underscore and try again.
     */
    if( pSymbol == NULL )
    {
        char withUnder[strlen(pszSymbolName) + 2];
        withUnder[0] = '_'; withUnder[1] = 0;
        strcat(withUnder, pszSymbolName);
        pSymbol = dlsym( pLibrary, withUnder );
    }
#endif

    if( pSymbol == NULL )
    {
        CPLError( CE_Failure, CPLE_AppDefined,
                  "%s", dlerror() );
        return NULL;
    }
    
    return( pSymbol );
}