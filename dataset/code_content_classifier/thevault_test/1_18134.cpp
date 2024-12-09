int
cllConnectRda( icatSessionStruct *icss ) {
    int stat;
    OCIEnv           *p_env;
    OCISvcCtx        *p_svc;

    char userName[110];
    char databaseName[110];
    char *cp1, *cp2;
    int i, atFound;

    p_svc = ( OCISvcCtx * )icss->connectPtr;
    p_env = ( OCIEnv * )icss->environPtr;

    atFound = 0;
    userName[0] = '\0';
    databaseName[0] = '\0';
    cp1 = userName;
    cp2 = icss->databaseUsername;
    for ( i = 0; i < 100; i++ ) {
        if ( *cp2 == '@' ) {
            atFound = 1;
            *cp1 = '\0';
            cp1 = databaseName;
            cp2++;
        }
        else {
            if ( *cp2 == '\0' ) {
                *cp1 = '\0';
                break;
            }
            else {
                *cp1++ = *cp2++;
            }
        }
    }
    if ( atFound == 0 ) {
        rodsLog( LOG_ERROR, "no @ in the database user name" );
        return CAT_INVALID_ARGUMENT;
    }

    stat = OCILogon( p_env, p_err, &p_svc, ( OraText * )userName,
                     strlen( userName ),
                     ( OraText * )icss->databasePassword,
                     strlen( icss->databasePassword ),
                     ( OraText * )databaseName, strlen( databaseName ) );

    if ( stat != OCI_SUCCESS ) {
        rodsLog( LOG_ERROR, "cllConnectRda: OCILogon failed: %d", stat );
        logOraError( LOG_ERROR, p_err, stat );
        return CAT_CONNECT_ERR;
    }

    icss->connectPtr = p_svc;
    return 0;
}