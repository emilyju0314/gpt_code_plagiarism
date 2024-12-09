static char *strnew(const char *val) {
    if ( val == NULL ) return(NULL);
    char *s = new char[strlen(val)+1];
    strcpy(s, val);
    return(s);
}