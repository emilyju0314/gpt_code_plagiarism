int
sTest( int i1, int i2 ) {
    int i;
    int keepVal;

    if ( firstCall ) {
        icatGeneralQuerySetup(); /* initialize */
    }
    firstCall = 0;

    for ( i = 0; i < nTables; i++ ) {
        Tables[i].flag = 0;
        if ( i == i1 || i == i2 ) {
            Tables[i].flag = 1;
        }
    }
    nToFind = 2;
    keepVal = tScan( i1, -1 );
    if ( keepVal != 1 || nToFind != 0 ) {
        printf( "error failed to link %d to %d\n", i1, i2 );
    }
    else {
        printf( "SUCCESS linking %d to %d\n", i1, i2 );
    }
    return 0;
}