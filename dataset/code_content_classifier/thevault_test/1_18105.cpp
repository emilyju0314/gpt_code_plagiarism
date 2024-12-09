int
sFklink( const char *table1, const char *table2, const char *connectingSQL ) {
    if ( nLinks >= MAX_LINKS_TABLES_OR_COLUMNS ) {
        rodsLog( LOG_ERROR, "fklink table full %d", CAT_TOO_MANY_TABLES );
        return CAT_TOO_MANY_TABLES;
    }
    Links[nLinks].table1 = fkFindName( table1 );
    Links[nLinks].table2 = fkFindName( table2 );
    snprintf( Links[nLinks].connectingSQL, sizeof( Links[nLinks].connectingSQL ), "%s", connectingSQL );
    if ( debug > 1 ) printf( "link %d is from %d to %d\n", nLinks,
                                 Links[nLinks].table1,
                                 Links[nLinks].table2 );
    if ( debug2 ) printf( "T%2.2d L%2.2d T%2.2d\n",
                              Links[nLinks].table1,  nLinks,
                              Links[nLinks].table2 );
    nLinks++;
    return 0;
}