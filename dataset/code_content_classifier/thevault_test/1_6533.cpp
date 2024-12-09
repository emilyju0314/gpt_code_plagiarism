const char *
dumb_strcasestr(const char *string, const char *substr)
{
  int str_len, substr_len, cmplen, i;
  const char *ptr;

  str_len = strlen(string);
  substr_len = strlen(substr);
  cmplen = str_len - substr_len + 1;

  for (ptr = string, i=0; i<cmplen; i++, ptr++) {
    if (strncasecmp(ptr, substr, substr_len) == 0)
      return ptr;
  }
  return NULL;
}