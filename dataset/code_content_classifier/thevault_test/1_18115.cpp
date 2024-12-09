int
handleCompoundCondition( char *condition, int prevWhereLen ) {
    char tabAndColumn[MAX_SQL_SIZE_GQ];
    char condPart1[MAX_NAME_LEN * 2];
    static char condPart2[MAX_NAME_LEN * 2];
    static char conditionsForBind[MAX_NAME_LEN * 2];
    static int conditionsForBindIx = 0;
    int status;

    if ( prevWhereLen < 0 ) { /* reinitialize */
        conditionsForBindIx = 0;
        return 0;
    }

    /* If there's an AND that was appended, need to include it */
    int i = prevWhereLen;
    while ( whereSQL[i] == ' ' ) {
        i++;
    }
    if ( strncmp( whereSQL + i, "AND", 3 ) == 0 ) {
        prevWhereLen = i + 3;
    }

    if ( !rstrcpy( tabAndColumn, ( char * )&whereSQL[prevWhereLen], MAX_SQL_SIZE_GQ ) ) {
        return USER_STRLEN_TOOLONG;
    }

    whereSQL[prevWhereLen] = '\0'; /* reset whereSQL to previous spot */
    if ( !rstrcat( whereSQL, " ( ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }

    if ( !rstrcpy( condPart2, condition, MAX_NAME_LEN * 2 ) ) {
        return USER_STRLEN_TOOLONG;
    }

    while ( true ) {
        if ( !rstrcpy( condPart1, condPart2, MAX_NAME_LEN * 2 ) ) {
            return USER_STRLEN_TOOLONG;
        }

        char* orptr = strstr( condPart1, "||" );
        char* andptr = strstr( condPart1, "&&" );
        char *cptr = NULL;
        int type = 0;
        if ( orptr != NULL && ( andptr == NULL || orptr < andptr ) ) {
            cptr = orptr;
            type = 1;
        }
        else if ( andptr != NULL && ( orptr == NULL || andptr < orptr ) ) {
            cptr = andptr;
            type = 2;
        }
        else {
            break;
        }
        *cptr = '\0';
        cptr += 2; /* past the && or || */
        if ( !rstrcpy( condPart2, cptr, MAX_NAME_LEN * 2 ) ) {
            return USER_STRLEN_TOOLONG;
        }

        if ( !rstrcat( whereSQL, tabAndColumn, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcpy( ( char* )&conditionsForBind[conditionsForBindIx], condPart1,
                       ( MAX_SQL_SIZE_GQ * 2 ) - conditionsForBindIx ) ) {
            return USER_STRLEN_TOOLONG;
        }
        status = insertWhere( ( char* )&conditionsForBind[conditionsForBindIx], 0 );
        if ( status ) {
            return status;
        }
        conditionsForBindIx += strlen( condPart1 ) + 1;

        if ( type == 1 ) {
            if ( !rstrcat( whereSQL, " OR ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
        else if ( type == 2 ) {
            if ( !rstrcat( whereSQL, " AND ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
    }

    if ( !rstrcat( whereSQL, tabAndColumn, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    status = insertWhere( condPart2, 0 );
    if ( status ) {
        return status;
    }

    if ( !rstrcat( whereSQL, " ) ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    return 0;
}