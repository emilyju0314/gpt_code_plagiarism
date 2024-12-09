int
bindTheVariables( OCIStmt *p_statement, const char *sql ) {
    int myBindVarCount;
    int stat;
    int i;

    for ( i = 0; i < MAX_BIND_VARS; i++ ) {
        p_bind[i] = NULL;
    }
    if ( bindName[0] == '\0' ) {
        /* I believe we need a static array of these bind names so
           initialize them if they haven't been already.
        */
        for ( i = 0; i < MAX_BIND_VARS; i++ ) {
            snprintf( &bindName[i * 5], 5, ":%d", i + 1 );
        }
    }

    myBindVarCount = cllBindVarCount;
    cllBindVarCountPrev = cllBindVarCount; /* save in case we need to log error */
    cllBindVarCount = 0; /* reset for next call */

    if ( myBindVarCount > 0 ) {
        if ( myBindVarCount > MAX_BIND_VARS ) {
            return CAT_INVALID_ARGUMENT;
        }
        for ( i = 0; i < myBindVarCount; i++ ) {
            int len, len2;
            len = strlen( ( char* )&bindName[i * 5] );
            len2 = strlen( cllBindVars[i] ) + 1;
            stat =  OCIBindByName( p_statement, &p_bind[i], p_err,
                                   ( OraText * )&bindName[i * 5],
                                   len,
                                   ( dvoid * )cllBindVars[i],
                                   len2,
                                   SQLT_STR,
                                   0, 0, 0, 0, 0,
                                   OCI_DEFAULT );

            if ( stat != OCI_SUCCESS ) {
                rodsLog( LOG_ERROR, "cllExecNoResult: OCIBindByName failed: %d",
                         stat );
                rodsLog( LOG_ERROR, "sql:%s", sql );
                logOraError( LOG_ERROR, p_err, stat );
                return CAT_OCI_ERROR;
            }
        }
    }
    return 0;
}