static void AddStringsToUnicharset(const std::vector<std::string> &strings, int norm_mode,
                                   UNICHARSET *unicharset) {
  for (const auto &string : strings) {
    std::vector<std::string> normalized;
    if (NormalizeCleanAndSegmentUTF8(UnicodeNormMode::kNFC, OCRNorm::kNone,
                                     static_cast<GraphemeNormMode>(norm_mode),
                                     /*report_errors*/ true, string.c_str(), &normalized)) {
      for (const std::string &normed : normalized) {
        // normed is a UTF-8 encoded string
        if (normed.empty() || IsUTF8Whitespace(normed.c_str())) {
          continue;
        }
        unicharset->unichar_insert(normed.c_str());
      }
    } else {
      tprintf("Normalization failed for string '%s'\n", string.c_str());
    }
  }
}