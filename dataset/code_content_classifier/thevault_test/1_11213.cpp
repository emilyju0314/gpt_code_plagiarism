int UNICHARSET::step(const char *str) const {
  std::vector<UNICHAR_ID> encoding;
  std::vector<char> lengths;
  encode_string(str, true, &encoding, &lengths, nullptr);
  if (encoding.empty() || encoding[0] == INVALID_UNICHAR_ID) {
    return 0;
  }
  return lengths[0];
}