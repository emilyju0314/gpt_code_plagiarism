int cllTest( const char *userArg, const char *pwArg ) {
    int i;
    int j, k;
    int OK;
    int stmt;
    int numOfCols;
    char userName[500];
    int numRows;

    struct passwd *ppasswd;
    icatSessionStruct icss;

    icss.stmtPtr[0] = 0;
    rodsLogSqlReq( 1 );
    OK = 1;
    i = cllOpenEnv( &icss );
    if ( i != 0 ) {
        OK = 0;
    }

    if ( userArg == 0 || *userArg == '\0' ) {
        ppasswd = getpwuid( getuid() );  /* get user passwd entry             */
        strcpy( userName, ppasswd->pw_name ); /* get user name                  */
    }
    else {
        strncpy( userName, userArg, 500 );
    }
    printf( "userName=%s\n", userName );
    printf( "password=%s\n", pwArg );

    strncpy( icss.databaseUsername, userName, DB_USERNAME_LEN );
    if ( pwArg == 0 || *pwArg == '\0' ) {
        strcpy( icss.databasePassword, "" );
    }
    else {
        strncpy( icss.databasePassword, pwArg, DB_PASSWORD_LEN );
    }

    i = cllConnect( &icss );
    if ( i != 0 ) {
        exit( -1 );
    }

    i = cllExecSqlNoResult( &icss, "drop table test" );

    i = cllExecSqlNoResult( &icss, "create table test (i integer, a2345678901234567890123456789j integer, a varchar(50) )" );
    if ( i != 0 && i != CAT_SUCCESS_BUT_WITH_NO_INFO ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss,
                            "insert into test values ('1', '2', 'asdfas')" );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "commit" );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "insert into test values (2, 3, 'a')" );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "commit" );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "bad sql" );
    if ( i == 0 ) {
        OK = 0;    /* should fail, if not it's not OK */
    }

    i = cllExecSqlNoResult( &icss, "delete from test where i = '1'" );
    if ( i != 0 && i != CAT_SUCCESS_BUT_WITH_NO_INFO ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "commit" );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllExecSqlWithResult( &icss, &stmt, "select * from test where a = 'a'" );
    if ( i != 0 ) {
        OK = 0;
    }

    if ( i == 0 ) {
        numOfCols = 1;
        for ( j = 0; j < 10 && numOfCols > 0; j++ ) {
            i = cllGetRow( &icss, stmt );
            if ( i != 0 ) {
                OK = 0;
                break;
            }
            else {
                numOfCols = icss.stmtPtr[stmt]->numOfCols;
                if ( numOfCols == 0 ) {
                    printf( "No more rows returned\n" );
                    i = cllFreeStatement( &icss, stmt );
                }
                else {
                    for ( k = 0; k < numOfCols || k < icss.stmtPtr[stmt]->numOfCols; k++ ) {
                        printf( "resultValue[%d]=%s\n", k,
                                icss.stmtPtr[stmt]->resultValue[k] );
                    }
                }
            }
        }
    }

    cllBindVars[cllBindVarCount++] = "a";
    i = cllExecSqlWithResult( &icss, &stmt,
                              "select * from test where a = ?" );
    if ( i != 0 ) {
        OK = 0;
    }

    numRows = 0;
    if ( i == 0 ) {
        numOfCols = 1;
        for ( j = 0; j < 10 && numOfCols > 0; j++ ) {
            i = cllGetRow( &icss, stmt );
            if ( i != 0 ) {
                OK = 0;
            }
            else {
                numOfCols = icss.stmtPtr[stmt]->numOfCols;
                if ( numOfCols == 0 ) {
                    printf( "No more rows returned\n" );
                    i = cllFreeStatement( &icss, stmt );
                }
                else {
                    numRows++;
                    for ( k = 0; k < numOfCols || k < icss.stmtPtr[stmt]->numOfCols; k++ ) {
                        printf( "resultValue[%d]=%s\n", k,
                                icss.stmtPtr[stmt]->resultValue[k] );
                    }
                }
            }
        }
    }

    if ( numRows != 1 ) {
        printf( "Error: Did not return 1 row, %d instead\n", numRows );
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "drop table test" );
    if ( i != 0 && i != CAT_SUCCESS_BUT_WITH_NO_INFO ) {
        OK = 0;
    }

    i = cllExecSqlNoResult( &icss, "commit" );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllDisconnect( &icss );
    if ( i != 0 ) {
        OK = 0;
    }

    i = cllCloseEnv( &icss );
    if ( i != 0 ) {
        OK = 0;
    }

    if ( OK ) {
        printf( "The tests all completed normally\n" );
        return 0;
    }
    else {
        printf( "One or more tests DID NOT complete normally\n" );
        return -1;
    }
}