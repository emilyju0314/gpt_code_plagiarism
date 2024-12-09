std::string UNICHARSET::debug_str(UNICHAR_ID id) const {
  if (id == INVALID_UNICHAR_ID) {
    return std::string(id_to_unichar(id));
  }
  const CHAR_FRAGMENT *fragment = this->get_fragment(id);
  if (fragment) {
    return fragment->to_string();
  }
  const char *str = id_to_unichar(id);
  std::string result = debug_utf8_str(str);
  // Append a for lower alpha, A for upper alpha, and x if alpha but neither.
  if (get_isalpha(id)) {
    if (get_islower(id)) {
      result += "a";
    } else if (get_isupper(id)) {
      result += "A";
    } else {
      result += "x";
    }
  }
  // Append 0 if a digit.
  if (get_isdigit(id)) {
    result += "0";
  }
  // Append p is a punctuation symbol.
  if (get_ispunctuation(id)) {
    result += "p";
  }
  return result;
}