bool IsUnspecOrEmptyIP(const IPAddress& address) {
#if !defined(WEBRTC_WIN)
  return IPIsAny(address);
#else
  return address.family() == AF_UNSPEC;
#endif
}