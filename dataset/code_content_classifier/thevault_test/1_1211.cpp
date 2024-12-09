void hexDumpInternal(const char *txt, const uint8_t *ptr, size_t size)
{
  unsigned int lineLen = 0;

  printf("%s: size: %zu ptr: 0x%p\n", txt, size, (void *) ptr);

  while (size--)
  {
    // The data bytes
    printf("%02x ", *ptr++);

    ++lineLen;

    // Fixed line length or until we run out of data
    if ((lineLen == MAX_LINE_LEN) || (size == 0))
    {
      printf("\n");
      lineLen = 0;
    }
  }
}