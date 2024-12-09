void UNICHARSET::encode_string(const char *str, int str_index, int str_length,
                               std::vector<UNICHAR_ID> *encoding,
                               std::vector<char> *lengths,
                               unsigned *best_total_length,
                               std::vector<UNICHAR_ID> *best_encoding,
                               std::vector<char> *best_lengths) const {
  if (str_index > static_cast<int>(*best_total_length)) {
    // This is the best result so far.
    *best_total_length = str_index;
    *best_encoding = *encoding;
    if (best_lengths != nullptr) {
      *best_lengths = *lengths;
    }
  }
  if (str_index == str_length) {
    return;
  }
  int encoding_index = encoding->size();
  // Find the length of the first matching unicharset member.
  int length = ids.minmatch(str + str_index);
  if (length == 0 || str_index + length > str_length) {
    return;
  }
  do {
    if (ids.contains(str + str_index, length)) {
      // Successful encoding so far.
      UNICHAR_ID id = ids.unichar_to_id(str + str_index, length);
      encoding->push_back(id);
      lengths->push_back(length);
      encode_string(str, str_index + length, str_length, encoding, lengths,
                    best_total_length, best_encoding, best_lengths);
      if (static_cast<int>(*best_total_length) == str_length) {
        return; // Tail recursion success!
      }
      // Failed with that length, truncate back and try again.
      encoding->resize(encoding_index);
      lengths->resize(encoding_index);
    }
    int step = UNICHAR::utf8_step(str + str_index + length);
    if (step == 0) {
      step = 1;
    }
    length += step;
  } while (length <= UNICHAR_LEN && str_index + length <= str_length);
}