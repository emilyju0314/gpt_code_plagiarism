bool shellCommandString::ReplaceBetween(std::string str) const {
  if (argc_ < 3) return false;

  std::string kHaystack;
  int arg_offset_before = 3, arg_offset_after = 4, arg_offset_replacement = 5;

  kHaystack = str.empty()
    // Haystack is given as CLI argument
    ? argv_[2]
    // Haystack is given as function parameter
    : str;

  const std::string kBefore = argv_[arg_offset_before];
  const std::string kAfter = argv_[arg_offset_after];

  const std::string kReplacement = argc_ <= arg_offset_replacement
                                   ? ""
                                   : argv_[arg_offset_replacement];

  auto out = helper::String::ReplaceBetween(
      kHaystack, kBefore, kAfter, kReplacement);

  if (out.empty()) return false;

  std::cout << out;

  return true;
}