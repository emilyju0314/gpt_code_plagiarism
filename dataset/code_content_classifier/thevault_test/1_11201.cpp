std::string StringRenderer::ConvertFullwidthLatinToBasicLatin(const std::string &str) {
  std::string half_str;
  UNICHAR::const_iterator it_end = UNICHAR::end(str.c_str(), str.length());
  for (UNICHAR::const_iterator it = UNICHAR::begin(str.c_str(), str.length()); it != it_end; ++it) {
    char32 half_char = FullwidthToHalfwidth(*it);
    // Convert fullwidth Latin characters to their halfwidth forms
    // only if halfwidth forms are printable and non-space 7-bit ASCII.
    if (IsInterchangeValid7BitAscii(half_char) && isprint(half_char) && !isspace(half_char)) {
      half_str.append(EncodeAsUTF8(half_char));
    } else {
      half_str.append(it.utf8_data(), it.utf8_len());
    }
  }
  return half_str;
}