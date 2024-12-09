int inet_pton_v4(const char* src, void* dst) {
  const int kIpv4AddressSize = 4;
  int found = 0;
  const char* src_pos = src;
  unsigned char result[kIpv4AddressSize] = {0};

  while (*src_pos != '\0') {
    // strtol won't treat whitespace characters in the begining as an error,
    // so check to ensure this is started with digit before passing to strtol.
    if (!isdigit(*src_pos)) {
      return 0;
    }
    char* end_pos;
    long value = strtol(src_pos, &end_pos, 10);
    if (value < 0 || value > 255 || src_pos == end_pos) {
      return 0;
    }
    ++found;
    if (found > kIpv4AddressSize) {
      return 0;
    }
    result[found - 1] = static_cast<unsigned char>(value);
    src_pos = end_pos;
    if (*src_pos == '.') {
      // There's more.
      ++src_pos;
    } else if (*src_pos != '\0') {
      // If it's neither '.' nor '\0' then return fail.
      return 0;
    }
  }
  if (found != kIpv4AddressSize) {
    return 0;
  }
  memcpy(dst, result, sizeof(result));
  return 1;
}