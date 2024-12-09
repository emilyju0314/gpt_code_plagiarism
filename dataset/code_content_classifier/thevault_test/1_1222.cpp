int errKeySpec(const char *str)
{
  fprintf(stderr, "error: unrecognized keyspec \"%s\"\n", str);
  return -1;
}