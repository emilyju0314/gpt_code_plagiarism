int
addBetweenClauseToWhere( char *inArg ) {
    int i, len;
    int startIx, endIx;
    int nput = 0;
    int quoteState = 0;
    char tmpStr[MAX_SQL_SIZE_GQ];
    static char inStrings[MAX_SQL_SIZE_GQ];
    int inStrIx = 0;
    int ncopy;
    if ( !rstrcat( whereSQL, " BETWEEN ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    len = strlen( inArg );
    for ( i = 0; i < len + 1; i++ ) {
        if ( inArg[i] == '\'' ) {
            quoteState++;
            if ( quoteState == 1 ) {
                startIx = i + 1;
            }
            if ( quoteState == 2 ) {
                quoteState = 0;
                endIx = i - 1;
                if ( nput == 0 ) {
                    if ( !rstrcat( whereSQL, "?", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
                }
                else {
                    if ( !rstrcat( whereSQL, " AND ? ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
                }
                nput++;

                /* Add the quoted string as a bind variable so user can't
                   execute arbitrary code */
                tmpStr[0] = '\0';
                ncopy = endIx - startIx + 1;
                rstrncat( tmpStr, ( char * )&inArg[startIx], ncopy, MAX_SQL_SIZE_GQ );
                if ( !rstrcpy( ( char * )&inStrings[inStrIx], tmpStr,
                               MAX_SQL_SIZE_GQ - inStrIx ) ) {
                    return USER_STRLEN_TOOLONG;
                }
                inStrings[inStrIx + ncopy] = '\0';
                if ( cllBindVarCount + 1 >= MAX_BIND_VARS ) { // JMC - backport 4848
                    return CAT_BIND_VARIABLE_LIMIT_EXCEEDED;
                }

                cllBindVars[cllBindVarCount++] = ( char * )&inStrings[inStrIx];
                inStrIx = inStrIx + ncopy + 1;
            }
        }
    }
    if ( nput != 2 ) {
        return CAT_INVALID_ARGUMENT;
    }
    return 0;
}