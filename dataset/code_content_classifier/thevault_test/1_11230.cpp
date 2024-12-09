bool UNICHARSET::AnyRepeatedUnicodes() const {
  int start_id = 0;
  if (has_special_codes()) {
    start_id = SPECIAL_UNICHAR_CODES_COUNT;
  }
  for (unsigned id = start_id; id < unichars.size(); ++id) {
    // Convert to unicodes.
    std::vector<char32> unicodes = UNICHAR::UTF8ToUTF32(get_normed_unichar(id));
    for (size_t u = 1; u < unicodes.size(); ++u) {
      if (unicodes[u - 1] == unicodes[u]) {
        return true;
      }
    }
  }
  return false;
}