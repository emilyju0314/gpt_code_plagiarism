int findCycles( int startTable ) {
    int i, status;
    int treeNum;

    if ( firstCall ) {
        icatGeneralQuerySetup(); /* initialize */
    }
    firstCall = 0;

    for ( i = 0; i < nTables; i++ ) {
        Tables[i].flag = 0;
    }
    treeNum = 0;

    if ( startTable != 0 ) {
        if ( startTable > nTables ) {
            return CAT_INVALID_ARGUMENT;
        }
        treeNum++;
        status = tCycleChk( startTable, -1, treeNum );
        if ( debug > 1 ) {
            printf( "tree %d status %d\n", treeNum, status );
        }
        if ( status ) {
            return status;
        }
    }

    for ( i = 0; i < nTables; i++ ) {
        if ( Tables[i].flag == 0 ) {
            treeNum++;
            status = tCycleChk( i, -1, treeNum );
            if ( debug > 1 ) {
                printf( "tree %d status %d\n", treeNum, status );
            }
            if ( status ) {
                return status;
            }
        }
    }
    return 0;
}