int
cllFreeStatement( icatSessionStruct *icss, int statementNumber ) {
    int stat;
    int i;
    OCIEnv           *p_env;

    icatStmtStrct *myStatement;
    OCIStmt  *p_statement;

    p_env = ( OCIEnv * )icss->environPtr;

    myStatement = icss->stmtPtr[statementNumber];
    if ( myStatement == NULL ) { /* already freed */
        return 0;
    }
    p_statement = ( OCIStmt * )myStatement->stmtPtr;

    for ( i = 0; i < myStatement->numOfCols; i++ ) {
        free( myStatement->resultValue[i] );
        free( myStatement->resultColName[i] );
    }

    if ( p_statement != NULL ) {
        stat = OCIHandleFree(
                   ( dvoid * )p_statement,
                   OCI_HTYPE_STMT );

        if ( stat != OCI_SUCCESS ) {
            rodsLog( LOG_ERROR, "cllFreeStatement: OCIHandleFree failed: %d",
                     stat );
            logOraError( LOG_ERROR, p_err, stat );
            return CAT_OCI_ERROR;
        }
    }

    free( myStatement );
    icss->stmtPtr[statementNumber] = 0; /* indicate that the statement is free */

    return 0;
}