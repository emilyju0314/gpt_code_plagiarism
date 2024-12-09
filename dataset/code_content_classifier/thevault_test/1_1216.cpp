int readNumFromFile(const char *fileName, unsigned int *numptr)
{
  int res = -1;
  res = readDataFromFile(fileName, numptr, sizeof(unsigned int));
  if (res != 0)
  {
    res = -1;
  }

  return res;
}