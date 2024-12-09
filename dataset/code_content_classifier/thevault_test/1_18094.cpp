static
int cmlGetOneRowFromSqlV3( const char *sql,
                           char *cVal[],
                           int cValSize[],
                           int numOfCols,
                           icatSessionStruct *icss ) {
    int i, j, stmtNum;
    char updatedSql[MAX_SQL_SIZE + 1];

//TODO: this should be a function, probably inside low-level icat
#ifdef ORA_ICAT
    strncpy( updatedSql, sql, MAX_SQL_SIZE );
    updatedSql[MAX_SQL_SIZE] = '\0';
#else
    strncpy( updatedSql, sql, MAX_SQL_SIZE );
    updatedSql[MAX_SQL_SIZE] = '\0';
    /* Verify there no limit or offset statement */
    if ( ( strstr( updatedSql, "limit " ) == NULL ) && ( strstr( updatedSql, "offset " ) == NULL ) ) {
        /* add 'limit 1' for performance improvement */
        strncat( updatedSql, " limit 1", MAX_SQL_SIZE );
        rodsLog( LOG_DEBUG1, "cmlGetOneRowFromSqlV3 %s", updatedSql );
    }
#endif

    i = cllExecSqlWithResult( icss, &stmtNum, updatedSql );

    if ( i != 0 ) {
        if ( i <= CAT_ENV_ERR ) {
            return ( i );   /* already an iRODS error code */
        }
        return CAT_SQL_ERR;
    }
    i = cllGetRow( icss, stmtNum );
    if ( i != 0 )  {
        cllFreeStatement( icss, stmtNum );
        return CAT_GET_ROW_ERR;
    }
    if ( icss->stmtPtr[stmtNum]->numOfCols == 0 ) {
        cllFreeStatement( icss, stmtNum );
        return CAT_NO_ROWS_FOUND;
    }
    for ( j = 0; j < numOfCols && j < icss->stmtPtr[stmtNum]->numOfCols ; j++ ) {
        rstrcpy( cVal[j], icss->stmtPtr[stmtNum]->resultValue[j], cValSize[j] );
    }

    i = cllFreeStatement( icss, stmtNum );
    return j;

}