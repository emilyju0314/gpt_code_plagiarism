int
cllGetRowCount( icatSessionStruct *icss, int statementNumber ) {
    int i, stat;

    icatStmtStrct *myStatement;
    OCIStmt  *p_statement;
    OCIParam *p_param = ( OCIParam * ) 0;
    ub4 rowCount;
    ub4 *pUb4;

    void * vptr;
    vptr = alignDouble( ( void * )&rowCount );

    /* malloc it so that it's aligned properly, else can get
       bus errors when doing 64-bit addressing */
    pUb4 = ( ub4 * )calloc( rowCount, sizeof( ub4 ) ); // JMC cppcheck - use of uninit var

    myStatement = icss->stmtPtr[statementNumber];
    p_statement = ( OCIStmt * )myStatement->stmtPtr;
    stat = OCIParamGet( ( dvoid * )p_statement, OCI_HTYPE_STMT, p_err,
                        ( dvoid ** )&p_param, ( ub4 ) 1 );
    if ( stat == OCI_SUCCESS ) {
        stat = OCIAttrGet( ( dvoid* ) p_param, ( ub4 ) OCI_DTYPE_PARAM,
                           pUb4, ( ub4 * ) 0, ( ub4 ) OCI_ATTR_ROW_COUNT,
                           ( OCIError * ) p_err );
        if ( stat != OCI_SUCCESS ) {
            rodsLog( LOG_ERROR, "cllGetRowCount: OCIAttrGet failed: %d", stat );
            logOraError( LOG_ERROR, p_err, stat );
            free( pUb4 );
            return CAT_OCI_ERROR;
        }
    }
    else {   // JMC - catch failure
        rodsLog( LOG_ERROR, "cllGetRowCount :: OCIParamGet failed." );
        free( pUb4 );
        return CAT_OCI_ERROR;
    }
    rowCount = *pUb4;
    i = rowCount;
    free( pUb4 );
    return rowCount;
}