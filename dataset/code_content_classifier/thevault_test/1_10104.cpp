int Log(const char* format, ...) {
  int result = 0;
  if (FLAGS_verbose) {
    va_list args;
    va_start(args, format);
    result = vprintf(format, args);
    va_end(args);
  }
  return result;
}