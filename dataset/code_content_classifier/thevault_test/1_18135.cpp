int
convertSqlToOra( const char *sql, char *sqlOut ) {
    const char *cp1 = sql;
    char *cp2 = sqlOut;
    const char * const cpEnd = cp2 + MAX_SQL_SIZE - 2;
    int i = 1;
    while ( *cp1 != '\0' ) {
        if ( *cp1 != '?' ) {
            *cp2++ = *cp1++;
        }
        else {
            *cp2++ = ':';
            /* handle cases with up to 999 bind variables */
            int tens = i / 10 ;
            const int ones = i % 10;
            const int hundreds = i / 100;
            if ( hundreds > 0 ) {
                tens = ( i - ( hundreds * 100 ) ) / 10;
                *cp2++ = hundreds + '0';
            }
            if ( hundreds > 0 || tens > 0 ) {
                *cp2++ = tens + '0';
            }
            *cp2++ = ones + '0';
            cp1++;
            i++;
        }
        if ( cp2 > cpEnd ) {
            return -1;
        }
    }
    *cp2 = '\0';
    return 0;
}