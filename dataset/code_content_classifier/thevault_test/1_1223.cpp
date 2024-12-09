int errAlgo(const char *str)
{
  fprintf(stderr, "error: unrecognized algorithm \"%s\"\n", str);
  return -1;
}