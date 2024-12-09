int
cllGetRow( icatSessionStruct *icss, int statementNumber ) {
    static OCIStmt          *p_statement;
    int nCols, stat;

    icatStmtStrct *myStatement;

    myStatement = icss->stmtPtr[statementNumber];
    nCols = myStatement->numOfCols;
    p_statement = ( OCIStmt * )myStatement->stmtPtr;

    stat = OCIStmtFetch( p_statement, p_err, ( ub4 )1, ( ub2 )0,
                         ( ub4 ) OCI_DEFAULT );
    if ( stat != OCI_SUCCESS && stat != OCI_NO_DATA ) {
        logOraError( LOG_ERROR, p_err, stat );
        _cllFreeStatementColumns( icss, statementNumber );
        myStatement->numOfCols = 0;
        rodsLog( LOG_ERROR, "cllGetRow: Fetch failed: %d", stat );
        return -1;
    }
    if ( stat == OCI_SUCCESS ) {
        return 0;
    }
    _cllFreeStatementColumns( icss, statementNumber );
    myStatement->numOfCols = 0;
    return 0;
}