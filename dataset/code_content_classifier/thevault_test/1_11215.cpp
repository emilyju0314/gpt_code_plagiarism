bool UNICHARSET::encode_string(const char *str, bool give_up_on_failure,
                               std::vector<UNICHAR_ID> *encoding,
                               std::vector<char> *lengths,
                               unsigned *encoded_length) const {
  std::vector<UNICHAR_ID> working_encoding;
  std::vector<char> working_lengths;
  std::vector<char> best_lengths;
  encoding->clear(); // Just in case str is empty.
  auto str_length = strlen(str);
  unsigned str_pos = 0;
  bool perfect = true;
  while (str_pos < str_length) {
    encode_string(str, str_pos, str_length, &working_encoding, &working_lengths,
                  &str_pos, encoding, &best_lengths);
    if (str_pos < str_length) {
      // This is a non-match. Skip one utf-8 character.
      perfect = false;
      if (give_up_on_failure) {
        break;
      }
      int step = UNICHAR::utf8_step(str + str_pos);
      if (step == 0) {
        step = 1;
      }
      encoding->push_back(INVALID_UNICHAR_ID);
      best_lengths.push_back(step);
      str_pos += step;
      working_encoding = *encoding;
      working_lengths = best_lengths;
    }
  }
  if (lengths != nullptr) {
    *lengths = best_lengths;
  }
  if (encoded_length != nullptr) {
    *encoded_length = str_pos;
  }
  return perfect;
}