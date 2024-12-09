void RemoveANSIEscapeSequencesFromString(char *str) {
  if (!str)
    return;

  // We are going to remove the escape sequences in place.
  char *s = str;
  char *z = str;
  while (*s != '\0') {
    CHECK_GE(s, z);
    // Skip over ANSI escape sequences with pointer 's'.
    if (*s == '\033' && *(s + 1) == '[') {
      s = internal_strchrnul(s, 'm');
      if (*s == '\0') {
        break;
      }
      s++;
      continue;
    }
    // 's' now points at a character we want to keep. Copy over the buffer
    // content if the escape sequence has been perviously skipped andadvance
    // both pointers.
    if (s != z)
      *z = *s;

    // If we have not seen an escape sequence, just advance both pointers.
    z++;
    s++;
  }

  // Null terminate the string.
  *z = '\0';
}