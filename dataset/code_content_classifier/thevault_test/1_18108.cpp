int
sGetColumnInfo( int defineVal, char **tableName, char **columnName ) {
    int i;
    for ( i = 0; i < nColumns; i++ ) {
        if ( Columns[i].defineValue == defineVal ) {
            *tableName = Columns[i].tableName;
            *columnName = Columns[i].columnName;
            return 0;
        }
    }
    return CAT_INVALID_ARGUMENT;
}