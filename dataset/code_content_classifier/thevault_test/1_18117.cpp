int
addInClauseToWhereForParentOf( char *inArg ) {
    int i, len;
    int nput = 0;
    char tmpStr[MAX_SQL_SIZE_GQ];
    static char inStrings[MAX_SQL_SIZE_GQ];
    int inStrIx = 0;

    if ( !rstrcat( whereSQL, " IN (", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    len = strlen( inArg );
    for ( i = 0; i < len + 1; i++ ) {
        if ( inArg[i] == '/' || inArg[i] == ' ' || inArg[i] == '\0' ) {
            int ncopy = i;
            if ( nput == 0 ) {
                ncopy++;
            }
            if ( nput == 0 ) {
                if ( !rstrcat( whereSQL, "?", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
            }
            else {
                if ( !rstrcat( whereSQL, ", ?", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
            }
            nput++;

            /* Add the substing as a bind variable in case there are quotes */
            tmpStr[0] = '\0';
            rstrncat( tmpStr, inArg, ncopy, MAX_SQL_SIZE_GQ );
            if ( !rstrcpy( ( char * )&inStrings[inStrIx], tmpStr,
                           ( MAX_SQL_SIZE_GQ ) - inStrIx ) ) {
                return USER_STRLEN_TOOLONG;
            }
            inStrings[inStrIx + ncopy] = '\0';
            if ( cllBindVarCount + 1 >= MAX_BIND_VARS ) {
                return CAT_BIND_VARIABLE_LIMIT_EXCEEDED;
            }
            cllBindVars[cllBindVarCount++] = ( char * )&inStrings[inStrIx];
            inStrIx = inStrIx + ncopy + 1;
        }
    }
    if ( !rstrcat( whereSQL, ")", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    return 0;
}