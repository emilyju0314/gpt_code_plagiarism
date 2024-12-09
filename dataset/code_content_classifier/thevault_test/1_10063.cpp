const char* win32_inet_ntop(int af, const void *src,
                            char* dst, socklen_t size) {
  if (!src || !dst) {
    return NULL;
  }
  switch (af) {
    case AF_INET: {
      return inet_ntop_v4(src, dst, size);
    }
    case AF_INET6: {
      return inet_ntop_v6(src, dst, size);
    }
  }
  return NULL;
}