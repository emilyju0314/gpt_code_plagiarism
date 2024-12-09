void
handleMultiCollAVUConditions( int nConditions ) {
    int i;
    char *firstItem, *nextItem;
    char nextStr[20];

    /* In the whereSQL, change r_coll_meta_main.meta_attr_name to
       r_coll_meta_mnNN.meta_attr_name, where NN is index.  First one
       is OK, subsequent ones need a new name for each. */
    firstItem = strstr( whereSQL, "r_coll_meta_main.meta_attr_name" );
    if ( firstItem != NULL ) {
        *firstItem = 'x'; /* temporarily change 1st string */
    }
    for ( i = 2; i <= nConditions; i++ ) {
        nextItem = strstr( whereSQL, "r_coll_meta_main.meta_attr_name" );
        if ( nextItem != NULL ) {
            snprintf( nextStr, sizeof nextStr, "n%2.2d", i );
            *( nextItem + 13 ) = nextStr[0]; /* replace "ain" in main */
            *( nextItem + 14 ) = nextStr[1]; /* with nNN */
            *( nextItem + 15 ) = nextStr[2];
        }
    }
    if ( firstItem != NULL ) {
        *firstItem = 'r'; /* put it back */
    }

    /* Do similar for r_coll_meta_main.meta_attr_value.  */
    firstItem = strstr( whereSQL, "r_coll_meta_main.meta_attr_value" );
    if ( firstItem != NULL ) {
        *firstItem = 'x'; /* temporarily change 1st string */
    }
    for ( i = 2; i <= nConditions; i++ ) {
        nextItem = strstr( whereSQL, "r_coll_meta_main.meta_attr_value" );
        if ( nextItem != NULL ) {
            snprintf( nextStr, sizeof nextStr, "n%2.2d", i );
            *( nextItem + 13 ) = nextStr[0]; /* replace "ain" in main */
            *( nextItem + 14 ) = nextStr[1]; /* with nNN */
            *( nextItem + 15 ) = nextStr[2];
        }
    }
    if ( firstItem != NULL ) {
        *firstItem = 'r'; /* put it back */
    }


    /* In the fromSQL, add items for r_coll_metamapNN and
       r_coll_meta_mnNN */
    for ( i = 2; i <= nConditions; i++ ) {
        char newStr[100];
        snprintf( newStr, sizeof newStr,
                  ", R_OBJT_METAMAP r_coll_metamap%d, R_META_MAIN r_coll_meta_mn%2.2d ",
                  i, i );
        if ( !rstrcat( fromSQL, newStr, MAX_SQL_SIZE_GQ ) ) { return; }
    }

    /* In the whereSQL, add items for
       r_coll_metamapNN.meta_id = r_coll_meta_maNN.meta_id  and
       R_COLL_MAIN.coll_id = r_coll_metamap2.object_id
    */
    for ( i = 2; i <= nConditions; i++ ) {
        char newStr[100];
        snprintf( newStr, sizeof newStr,
                  " AND r_coll_metamap%d.meta_id = r_coll_meta_mn%2.2d.meta_id", i, i );
        if ( !rstrcat( whereSQL, newStr, MAX_SQL_SIZE_GQ ) ) { return; }
        snprintf( newStr, sizeof newStr,
                  " AND R_COLL_MAIN.coll_id = r_coll_metamap%d.object_id ", i );
        if ( !rstrcat( whereSQL, newStr, MAX_SQL_SIZE_GQ ) ) { return; }
    }
}