int
insertWhere( char *condition, int option ) {
    static int bindIx = 0;
    static char bindVars[MAX_SQL_SIZE_GQ + 100];
    char *cp1, *cpFirstQuote, *cpSecondQuote;
    char *cp;
    int i;
    char *thisBindVar;
    char tmpStr[20];
    char myCondition[20];
    char *condStart;

    if ( option == 1 ) { /* reinitialize */
        bindIx = 0;
        addInClauseToWhereForIn( condition, option );
        return 0;
    }

    condStart = condition;
    while ( *condStart == ' ' ) {
        condStart++;
    }

    cp = strstr( condition, "in" );
    if ( cp == NULL ) {
        cp = strstr( condition, "IN" );
    }
    if ( cp != NULL && cp == condStart ) {
        return addInClauseToWhereForIn( condition, 0 );
    }

    cp = strstr( condition, "between" );
    if ( cp == NULL ) {
        cp = strstr( condition, "BETWEEN" );
    }
    if ( cp != NULL && cp == condStart ) {
        return addBetweenClauseToWhere( condition );
    }

    cpFirstQuote = 0;
    cpSecondQuote = 0;
    for ( cp1 = condition; *cp1 != '\0'; cp1++ ) {
        if ( *cp1 == '\'' ) {
            if ( cpFirstQuote == 0 ) {
                cpFirstQuote = cp1;
            }
            else {
                cpSecondQuote = cp1; /* If embedded 's, skip them; it's OK*/
            }
        }
    }
    if ( strcmp( condition, "IS NULL" ) == 0 ) {
        if ( !rstrcat( whereSQL, " ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, condition, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, " ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        return 0;
    }
    if ( strcmp( condition, "IS NOT NULL" ) == 0 ) {
        if ( !rstrcat( whereSQL, " ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, condition, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, " ", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        return 0;
    }
    bindIx++;
    thisBindVar = ( char* )&bindVars[bindIx];
    if ( cpFirstQuote == 0 || cpSecondQuote == 0 ) {
        return CAT_INVALID_ARGUMENT;
    }
    if ( ( cpSecondQuote - cpFirstQuote ) + bindIx > MAX_SQL_SIZE_GQ + 90 ) {
        return CAT_INVALID_ARGUMENT;
    }

    for ( cp1 = cpFirstQuote + 1; cp1 < cpSecondQuote; cp1++ ) {
        bindVars[bindIx++] = *cp1;
    }
    bindVars[bindIx++] = '\0';
    if ( cllBindVarCount + 1 >= MAX_BIND_VARS ) { // JMC - backport 4848
        return CAT_BIND_VARIABLE_LIMIT_EXCEEDED;
    }

    cllBindVars[cllBindVarCount++] = thisBindVar;

    /* basic legality check on the condition */
    if ( ( cpFirstQuote - condition ) > 10 ) {
        return CAT_INVALID_ARGUMENT;
    }

    tmpStr[0] = ' ';
    i = 1;
    for ( cp1 = condition;; ) {
        tmpStr[i++] = *cp1++;
        if ( cp1 == cpFirstQuote ) {
            break;
        }
    }
    tmpStr[i] = '\0';
    if ( !rstrcpy( myCondition, tmpStr, 20 ) ) {
        return USER_STRLEN_TOOLONG;
    }

    cp = strstr( myCondition, "begin_of" );
    if ( cp != NULL ) {
        char tmpStr2[MAX_SQL_SIZE_GQ];
        cp1 = whereSQL + strlen( whereSQL ) - 1;
        while ( *cp1 != ' ' ) {
            cp1--;
        }
        cp1++;
        if ( !rstrcpy( tmpStr2, cp1, MAX_SQL_SIZE_GQ ) ) {
            return USER_STRLEN_TOOLONG;
        } /*use table/column name just added*/
#if ORA_ICAT
        if ( !rstrcat( whereSQL, "=substr(?,1,length(", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, tmpStr2, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, "))", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, " AND length(", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
#else
        if ( !rstrcat( whereSQL, "=substr(?,1,char_length(", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, tmpStr2, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, "))", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, " AND char_length(", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
#endif
        if ( !rstrcat( whereSQL, tmpStr2, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        if ( !rstrcat( whereSQL, ")>0", MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
    }
    else {
        cp = strstr( myCondition, "parent_of" );
        if ( cp != NULL ) {
            /* New version to replace begin_of in a call from
                   rsObjStat.c, as suggested by Andy Salnikov; add an IN
                   clause with each of the possible parent collection names;
                   this is faster, sometimes very much faster. */
            cllBindVarCount--; /* undo bind-var as it is not included now */
            int status = addInClauseToWhereForParentOf( thisBindVar ); // JMC - backport 4848
            if ( status < 0 ) {
                return ( status );   // JMC - backport 4848
            }
        }
        else {
            tmpStr[i++] = '?';
            tmpStr[i++] = ' ';
            tmpStr[i++] = '\0';
            if ( !rstrcat( whereSQL, tmpStr, MAX_SQL_SIZE_GQ ) ) { return USER_STRLEN_TOOLONG; }
        }
    }
    return checkCondition( myCondition );
}