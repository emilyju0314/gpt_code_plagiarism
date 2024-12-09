int readAllDataFromFile(const char *fileName, void *data, size_t maxSize)
{
  int res = -1;
  FILE *file = stdin;

  if ((fileName == NULL) || (data == NULL))
  {
     return res;
  }

  if (maxSize > 0)
  {
    memset(data, 0, maxSize);
  }

  if (strcmp(fileName, "-") != 0)
  {
    file = fopen(fileName, "r");
    if (!file)
    {
      printf("%s - cannot open file: %s\n", __FUNCTION__, fileName);
      return res;
    }
  }

  res = (int) fread(data, 1, maxSize, file);

  if (file != stdin)
  {
    fclose(file);
  }

  return res;
}