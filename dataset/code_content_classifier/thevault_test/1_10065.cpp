const char* inet_ntop_v4(const void* src, char* dst, socklen_t size) {
  if (size < INET_ADDRSTRLEN) {
    return NULL;
  }
  const struct in_addr* as_in_addr =
      reinterpret_cast<const struct in_addr*>(src);
  rtc::sprintfn(dst, size, "%d.%d.%d.%d",
                      as_in_addr->S_un.S_un_b.s_b1,
                      as_in_addr->S_un.S_un_b.s_b2,
                      as_in_addr->S_un.S_un_b.s_b3,
                      as_in_addr->S_un.S_un_b.s_b4);
  return dst;
}