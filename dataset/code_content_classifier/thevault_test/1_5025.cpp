std::vector<codepoint> decode(const std::vector<byte> &bytes) {
  // Initialize iterators pointing to start and end of bytes.
  auto iter = bytes.cbegin();
  auto end = bytes.cend();

  // Decode codepoints until there are no more bytes.
  std::vector<codepoint> codepoints = {};
  while (iter != end) {
    auto cp = next_codepoint(iter, end);
    codepoints.push_back(*cp);
  }

  return codepoints;
}