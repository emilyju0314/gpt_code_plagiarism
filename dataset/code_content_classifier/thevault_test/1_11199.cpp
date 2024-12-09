std::string StringRenderer::InsertWordJoiners(const std::string &text) {
  std::string out_str;
  const UNICHAR::const_iterator it_end = UNICHAR::end(text.c_str(), text.length());
  for (UNICHAR::const_iterator it = UNICHAR::begin(text.c_str(), text.length()); it != it_end;
       ++it) {
    // Add the symbol to the output string.
    out_str.append(it.utf8_data(), it.utf8_len());
    // Check the next symbol.
    UNICHAR::const_iterator next_it = it;
    ++next_it;
    bool next_char_is_boundary = (next_it == it_end || *next_it == ' ');
    bool next_char_is_combiner = (next_it == it_end) ? false : IsCombiner(*next_it);
    if (*it != ' ' && *it != '\n' && !next_char_is_boundary && !next_char_is_combiner) {
      out_str += kWordJoinerUTF8;
    }
  }
  return out_str;
}