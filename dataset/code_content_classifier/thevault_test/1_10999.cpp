static int is_simple_quote(const char *signed_str, int length) {
  const auto *str = reinterpret_cast<const unsigned char *>(signed_str);
  // Standard 1 byte quotes.
  return (length == 1 && (*str == '\'' || *str == '`')) ||
         // UTF-8 3 bytes curved quotes.
         (length == 3 &&
          ((*str == 0xe2 && *(str + 1) == 0x80 && *(str + 2) == 0x98) ||
           (*str == 0xe2 && *(str + 1) == 0x80 && *(str + 2) == 0x99)));
}