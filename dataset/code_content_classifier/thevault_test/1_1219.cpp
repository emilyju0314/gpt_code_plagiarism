int errRead(int res, size_t numBytes, const char *fileName)
{
  if (res < 0)
  {
    fprintf(stderr, "error: cannot read (%zu bytes) from file %s\n", numBytes, fileName);
  }

  return res < 0;
}