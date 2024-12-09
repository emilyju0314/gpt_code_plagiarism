int cmlGetOneRowFromSqlV2( const char *sql,
                           char *cVal[],
                           int maxCols,
                           std::vector<std::string> &bindVars,
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
        rodsLog( LOG_DEBUG1, "cmlGetOneRowFromSqlV2 %s", updatedSql );
    }
#endif

    i = cllExecSqlWithResultBV( icss, &stmtNum, updatedSql,
                                bindVars );

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
        return CAT_NO_ROWS_FOUND;
    }
    for ( j = 0; j < maxCols && j < icss->stmtPtr[stmtNum]->numOfCols ; j++ ) {
        cVal[j] = icss->stmtPtr[stmtNum]->resultValue[j];
    }

    return ( stmtNum ); /* 0 or positive is the statement number */
}