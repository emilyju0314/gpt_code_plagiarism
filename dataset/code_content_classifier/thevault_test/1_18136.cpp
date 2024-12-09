void
logTheBindVariables( int level ) {
    int i;
    char tmpStr[TMP_STR_LEN + 2];
    for ( i = 0; i < cllBindVarCountPrev; i++ ) {
        snprintf( tmpStr, TMP_STR_LEN, "bindVar[%d]=:%s:", i + 1, cllBindVars[i] );
        if ( level == 0 ) {
            rodsLogSql( tmpStr );
        }
        else {
            rodsLog( level, tmpStr );
        }
    }
}