int errWrite(int res, const char *fileName)
{
  if (res < 0)
  {
    fprintf(stderr, "error: cannot write to file %s\n", fileName);
  }

  return res < 0;
}