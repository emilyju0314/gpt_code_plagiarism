int
doTest5( rcComm_t *Conn,
         char *AvuName, char *order ) {
    genQueryInp_t genQueryInp;
    genQueryOut_t *genQueryOut;
    int status;
    char condition1[MAX_NAME_LEN];

    printf( "dotest5\n" );
    rodsLogSqlReq( 1 );

    memset( &genQueryInp, 0, sizeof( genQueryInp ) );

    snprintf( condition1, MAX_NAME_LEN, "='%s'", AvuName );
    addInxVal( &genQueryInp.sqlCondInp, COL_META_DATA_ATTR_NAME, condition1 );
    printf( "condition1 %s\n", condition1 );

    addInxIval( &genQueryInp.selectInp, COL_DATA_NAME, 0 );
    addInxIval( &genQueryInp.selectInp, COL_COLL_NAME, 0 );

    if ( order == NULL ) {
        addInxIval( &genQueryInp.selectInp, COL_META_DATA_ATTR_VALUE,
                    ORDER_BY_DESC );   /* regular, descending order */
    }
    else {
        if ( strcmp( order, "up" ) == 0 ) { /* ascending order */
            addInxIval( &genQueryInp.selectInp, COL_META_DATA_ATTR_VALUE,
                        ORDER_BY );
        }
        else {                           /* regular, descending order */
            addInxIval( &genQueryInp.selectInp, COL_META_DATA_ATTR_VALUE,
                        ORDER_BY_DESC );
        }
    }

    genQueryInp.maxRows = 2;       /* get two rows to better show the results,
				      but could just get 1 */

    status =  rcGenQuery( Conn, &genQueryInp, &genQueryOut );

    printf( "GenQuery status=%d\n", status );
    if ( status ) {
        printError( Conn, status, "rcGenQuery" );
    }

    if ( status == 0 ) {
        printf( "genQueryOut->totalRowCount=%d\n", genQueryOut->totalRowCount );

        printGenQOut( genQueryOut );

        if ( genQueryOut->continueInx > 0 ) { /* there are more rows available */
            genQueryInp.continueInx = genQueryOut->continueInx;
            genQueryInp.maxRows = 0; /* just close it out */
            status = rcGenQuery( Conn, &genQueryInp, &genQueryOut );
            printf( "close out rcGenQuery status=%d\n", status );
        }
    }
    return 0;
}