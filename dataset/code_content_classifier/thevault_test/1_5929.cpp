inline void
  send(const void* buf, size_t size)
  {
    getCurrentContext()->send(buf, size);
  }