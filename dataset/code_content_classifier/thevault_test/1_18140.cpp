int
cllNextValueString( const char *itemName, char *outString, int maxSize ) {
    snprintf( outString, maxSize, "%s.nextval", itemName );
    return 0;
}