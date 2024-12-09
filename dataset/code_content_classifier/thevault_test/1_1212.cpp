static inline void ksutilHexdump(const char *txt, const void *ptr, size_t size)
{
#ifdef DEBUG
  const uint8_t *p = (const uint8_t *) ptr;
  hexDumpInternal(txt, p, size);
#else
  (void) txt;
  (void) ptr;
  (void) size;
#endif
}