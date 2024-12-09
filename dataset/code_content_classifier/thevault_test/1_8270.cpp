static size_t
fetch_utf8_char(const char* p, unsigned int* pc)
{
  unsigned char c = *p;
  if ((c & 0x80) == 0)
    {
      *pc = c;
      return 1;
    }
  size_t len = 0;
  while ((c & 0x80) != 0)
    {
      ++len;
      c <<= 1;
    }
  unsigned int rc = *p & ((1 << (7 - len)) - 1);
  for (size_t i = 1; i < len; i++)
    {
      unsigned int u = p[i];
      rc <<= 6;
      rc |= u & 0x3f;
    }
  *pc = rc;
  return len;
}