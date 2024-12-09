int
sTableInit() {
    nLinks = 0;
    nTables = 0;
    nColumns = 0;
    memset( Links, 0, sizeof( Links ) );
    memset( Tables, 0, sizeof( Tables ) );
    memset( Columns, 0, sizeof( Columns ) );
    return 0;
}