int
compoundConditionSpecified( char *condition ) {
    char myCondition[MAX_NAME_LEN * 2];
    int quote;
    char *cptr;

    /* Simple case, not in the condition at all */
    if ( strstr( condition, "||" ) == NULL &&
            strstr( condition, "&&" ) == NULL ) {
        return 0;
    }

    /* Make a copy of the condition and erase the quoted strings */
    snprintf( myCondition, sizeof( myCondition ), "%s", condition );
    for ( cptr = myCondition, quote = 0; *cptr != '\0'; cptr++ ) {
        if ( *cptr == '\'' ) {
            if ( quote == 0 ) {
                quote = 1;
            }
            else {
                quote = 0;
            }
            *cptr = ' ';
        }
        if ( quote == 1 ) {
            *cptr = ' ';
        }
    }

    /* And now test again */
    if ( strstr( myCondition, "||" ) == NULL &&
            strstr( myCondition, "&&" ) == NULL ) {
        return 0;
    }
    return 1;
}