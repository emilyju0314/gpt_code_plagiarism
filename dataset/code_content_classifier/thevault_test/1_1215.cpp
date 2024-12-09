int readDataFromFile(const char *fileName, void *data, size_t size)
{
  int res = 0;

  res = readAllDataFromFile(fileName, data, size);
  if (res > 0 && (size_t) res == size)
  {
    res = 0;
  }

  return res;
}