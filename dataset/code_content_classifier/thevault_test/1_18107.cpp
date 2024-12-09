int
sTable( const char *tableName, const char *tableAlias, int cycler ) {
    if ( nTables >= MAX_LINKS_TABLES_OR_COLUMNS ) {
        rodsLog( LOG_ERROR, "sTable table full %d", CAT_TOO_MANY_TABLES );
        return CAT_TOO_MANY_TABLES;
    }
    snprintf( Tables[nTables].tableName, sizeof( Tables[nTables].tableName ), "%s", tableName );
    snprintf( Tables[nTables].tableAlias, sizeof( Tables[nTables].tableAlias ), "%s", tableAlias );
    Tables[nTables].cycler = cycler;
    if ( debug > 1 ) {
        printf( "table %d is %s\n", nTables, tableName );
    }
    nTables++;
    return 0;
}