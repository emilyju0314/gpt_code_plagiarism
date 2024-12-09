static void*
memdup(const void *data, size_t size)
{
  return memcpy(malloc(size), data, size);
}