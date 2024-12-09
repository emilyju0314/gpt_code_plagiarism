v8::Handle<v8::Value> ErrnoException(const char *prefix, int errnum) {
  char errbuf[128];
  snprintf(errbuf, sizeof(errbuf), "%s: %s", prefix, strerror(errnum));
  return StringException(errbuf);
}