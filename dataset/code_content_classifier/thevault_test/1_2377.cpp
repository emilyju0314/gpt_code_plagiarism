bool Is_Well_Formed_Keyword(Keyword const &key) {
  using namespace std;

  if (key.moniker == nullptr || key.func == nullptr)
    return false;
  char const *cptr = key.moniker;
  for (;;) {
    // Must be at the start of a C identifier, which begins with an alphabetic
    // character or an underscore.
    if (*cptr != '_' && !isalpha(*cptr))
      return false;

    // The subsequent characters in a C identifier must be alphanumeric
    // characters or underscores.
    while (*cptr == '_' || isalnum(*cptr))
      cptr++;

    // If the identifier is followed by a null, we're finished scanning a valid
    // keyword.
    if (*cptr == '\0')
      return true;

    // Otherwise, if the next character is not a space, it's not a valid
    // keyword.
    if (*cptr != ' ')
      return false;

    // Skip over the space. cptr should now point to the start of the next C
    // identifier, if this is a valid keyword.
    cptr++;
  }
}