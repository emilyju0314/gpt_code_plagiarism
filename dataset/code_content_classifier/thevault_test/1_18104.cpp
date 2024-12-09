int fkFindName( const char *tableName ) {
    int i;
    for ( i = 0; i < nTables; i++ ) {
        if ( strcmp( Tables[i].tableName, tableName ) == 0 ) {
            return i;
        }
    }
    rodsLog( LOG_ERROR, "fkFindName table %s unknown", tableName );
    return 0;
}