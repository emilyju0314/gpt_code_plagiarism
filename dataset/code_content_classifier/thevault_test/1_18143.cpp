int
_cllFreeStatementColumns( icatSessionStruct *icss, int statementNumber ) {
    int i;

    icatStmtStrct *myStatement;

    myStatement = icss->stmtPtr[statementNumber];

    for ( i = 0; i < myStatement->numOfCols; i++ ) {
        free( myStatement->resultValue[i] );
        free( myStatement->resultColName[i] );
    }
    return 0;
}