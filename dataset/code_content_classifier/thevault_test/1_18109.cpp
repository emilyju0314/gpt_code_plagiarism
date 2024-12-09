int
tablePresent( char *table, char *sqlText ) {
    int tokens, blank;
    char *cp1, *cp2;

    if ( debug > 1 ) {
        printf( "tablePresent table:%s:\n", table );
    }
    if ( debug > 1 ) {
        printf( "tablePresent sqlText:%s:\n", sqlText );
    }

    if ( strstr( sqlText, table ) == NULL ) {
        if ( debug > 1 ) {
            printf( "tablePresent return 0 (simple)\n" );
        }
        return ( 0 ); /* simple case */
    }

    tokens = 0;
    blank = 1;
    cp1 = table;
    for ( ; *cp1 != '\0' && *cp1 != ','; cp1++ ) {
        if ( *cp1 == ' ' ) {
            if ( blank == 0 ) {
                tokens++;
            }
            blank = 1;
        }
        else {
            blank = 0;
        }
    }
    if ( blank == 0 ) {
        tokens++;
    }

    if ( debug > 1 ) {
        printf( "tablePresent tokens=%d\n", tokens );
    }
    if ( tokens == 2 ) {
        return ( 1 ); /* 2 tokens and did match, is present */
    }

    /* have to check if the token appears in the first or second position */
    blank = 1;
    cp1 = sqlText;
    for ( ;; ) {
        cp2 = strstr( cp1, table );
        if ( cp2 == NULL ) {
            return 0;
        }
        tokens = 0;
        for ( ; *cp2 != '\0' && *cp2 != ','; cp2++ ) {
            if ( *cp2 == ' ' ) {
                if ( blank == 0 ) {
                    tokens++;
                }
                blank = 1;
            }
            else {
                blank = 0;
            }
        }
        if ( blank == 0 ) {
            tokens++;
        }
        if ( tokens == 1 ) {
            return 1;
        }
        cp1 = cp2;
    }
}