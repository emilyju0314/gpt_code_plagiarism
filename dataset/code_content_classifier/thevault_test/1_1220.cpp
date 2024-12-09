int errReadAll(int res, const char *fileName)
{
  if (res < 0)
  {
    fprintf(stderr, "error: cannot read from file %s\n", fileName);
  }

  return res < 0;
}