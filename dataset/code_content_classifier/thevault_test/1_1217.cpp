int errApi(int res, const char *apiName)
{
  if (res < 0)
  {
    fprintf(stderr, "error: %s returned %d\n", apiName, res);
  }

  return res < 0;
}