static void dnullcat(char*&wp, const char *string, int n = -1 ) {
  //DEBUG printf("DEBUG: dnullcat IN: <"); dnullprint(wp); printf(">\n");
  int inlen = ( n < 0 ) ? strlen(string) : n;
  if ( ! wp ) {
    wp = new char[inlen + 4];
    *(wp+0) = '\0';
    *(wp+1) = '\0';
  } else {
    int wplen = dnulllen(wp);
    // Make copy of wp into larger buffer
    char *tmp = new char[wplen + inlen + 4];
    memcpy(tmp, wp, wplen+2);	// copy of wp plus doublenull
    delete [] wp;			// delete old wp
    wp = tmp;			// use new copy
    //DEBUG printf("DEBUG: dnullcat COPY: <"); dnullprint(wp); printf("> (wplen=%d)\n", wplen);
  }

  // Find end of double null string
  //     *wp2 is left pointing at second null.
  //
  char *wp2 = wp;
  if ( *(wp2+0) != '\0' && *(wp2+1) != '\0' ) {
    for ( ; 1; wp2++ ) {
      if ( *(wp2+0) == '\0' && *(wp2+1) == '\0' ) {
        wp2++;
        break;
      }
    }
  }

  if ( n == -1 ) n = strlen(string);
  strncpy(wp2, string, n);

  // Leave string double-null terminated
  *(wp2+n+0) = '\0';
  *(wp2+n+1) = '\0';
  //DEBUG printf("DEBUG: dnullcat OUT: <"); dnullprint(wp); printf(">\n\n");
}