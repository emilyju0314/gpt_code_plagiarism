std::string StringRenderer::ConvertBasicLatinToFullwidthLatin(const std::string &str) {
  std::string full_str;
  const UNICHAR::const_iterator it_end = UNICHAR::end(str.c_str(), str.length());
  for (UNICHAR::const_iterator it = UNICHAR::begin(str.c_str(), str.length()); it != it_end; ++it) {
    // Convert printable and non-space 7-bit ASCII characters to
    // their fullwidth forms.
    if (IsInterchangeValid7BitAscii(*it) && isprint(*it) && !isspace(*it)) {
      // Convert by adding 0xFEE0 to the codepoint of 7-bit ASCII.
      char32 full_char = *it + 0xFEE0;
      full_str.append(EncodeAsUTF8(full_char));
    } else {
      full_str.append(it.utf8_data(), it.utf8_len());
    }
  }
  return full_str;
}