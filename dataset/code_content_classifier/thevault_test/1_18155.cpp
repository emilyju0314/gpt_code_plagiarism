int
checkModArgType( char *arg ) {
    if ( arg == NULL || strlen( arg ) == 0 ) {
        return CAT_INVALID_ARGUMENT;
    }
    if ( ':' != arg[1] ) {
        return 0;
    }
    switch ( arg[0] ) {
    case 'n':
        return 1;
    case 'v':
        return 2;
    case 'u':
        return 3;
    default:
        return 0;
    }
}