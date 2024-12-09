int errReadNum(int res, const char *fileName)
{
  if (res < 0)
  {
    fprintf(stderr, "error: cannot read number from file %s\n", fileName);
  }

  return res < 0;
}