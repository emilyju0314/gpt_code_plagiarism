bool UNICHARSET::encodable_string(const char *str,
                                  unsigned *first_bad_position) const {
  std::vector<UNICHAR_ID> encoding;
  return encode_string(str, true, &encoding, nullptr, first_bad_position);
}