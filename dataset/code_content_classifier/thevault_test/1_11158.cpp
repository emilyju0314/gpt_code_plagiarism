std::string UnicharCompress::GetEncodingAsString(const UNICHARSET &unicharset) const {
  std::string encoding;
  for (unsigned c = 0; c < encoder_.size(); ++c) {
    const RecodedCharID &code = encoder_[c];
    if (0 < c && c < SPECIAL_UNICHAR_CODES_COUNT && code == encoder_[c - 1]) {
      // Don't show the duplicate entry.
      continue;
    }
    encoding += std::to_string(code(0));
    for (int i = 1; i < code.length(); ++i) {
      encoding += "," + std::to_string(code(i));
    }
    encoding += "\t";
    if (c >= unicharset.size() ||
        (0 < c && c < SPECIAL_UNICHAR_CODES_COUNT && unicharset.has_special_codes())) {
      encoding += kNullChar;
    } else {
      encoding += unicharset.id_to_unichar(c);
    }
    encoding += "\n";
  }
  return encoding;
}