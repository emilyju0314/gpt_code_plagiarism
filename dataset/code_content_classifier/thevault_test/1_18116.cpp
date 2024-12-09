int
checkCondition( char *condition ) {
    char tmpStr[25];
    char *cp;

    if ( !rstrcpy( tmpStr, condition, 20 ) ) {
        return USER_STRLEN_TOOLONG;
    }
    for ( cp = tmpStr; *cp != '\0'; cp++ ) {
        if ( *cp == '<' ) {
            *cp = ' ';
        }
        if ( *cp == '>' ) {
            *cp = ' ';
        }
        if ( *cp == '=' ) {
            *cp = ' ';
        }
        if ( *cp == '!' ) {
            *cp = ' ';
        }
    }
    cp = strstr( tmpStr, "begin_of" );
    if ( cp != NULL ) {
        setBlank( cp, 8 );
    }
    cp = strstr( tmpStr, "parent_of" );
    if ( cp != NULL ) {
        setBlank( cp, 9 );
    }
    cp = strstr( tmpStr, "not" );
    if ( cp != NULL ) {
        setBlank( cp, 3 );
    }
    cp = strstr( tmpStr, "NOT" );
    if ( cp != NULL ) {
        setBlank( cp, 3 );
    }
    cp = strstr( tmpStr, "between" );
    if ( cp != NULL ) {
        setBlank( cp, 7 );
    }
    cp = strstr( tmpStr, "BETWEEN" );
    if ( cp != NULL ) {
        setBlank( cp, 7 );
    }
    cp = strstr( tmpStr, "like" );
    if ( cp != NULL ) {
        setBlank( cp, 4 );
    }
    cp = strstr( tmpStr, "LIKE" );
    if ( cp != NULL ) {
        setBlank( cp, 4 );
    }
    cp = strstr( tmpStr, "in" );
    if ( cp != NULL ) {
        setBlank( cp, 2 );
    }
    cp = strstr( tmpStr, "IN" );
    if ( cp != NULL ) {
        setBlank( cp, 2 );
    }

    for ( cp = tmpStr; *cp != '\0'; cp++ ) {
        if ( *cp != ' ' ) {
            return CAT_INVALID_ARGUMENT;
        }
    }
    return 0;
}