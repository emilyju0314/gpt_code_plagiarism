bool shellCommandString::ReplaceAfter(std::string str) const {
  if (argc_ < 3) return false;

  std::string kHaystack;
  int arg_offset_needle = 3, arg_offset_replacement = 4;

  kHaystack = str.empty()
              // Haystack is given as CLI argument
              ? argv_[2]
              // Haystack is given as function parameter
              : str;

  const std::string kNeedle = argv_[arg_offset_needle];

  const std::string kReplacement = argc_ <= arg_offset_replacement
                                   ? ""
                                   : argv_[arg_offset_replacement];

  auto offset_needle = kHaystack.find(kNeedle);
  if (offset_needle == std::string::npos) offset_needle = kHaystack.length();

  std::cout << kHaystack.substr(0, offset_needle) + kReplacement;

  return true;
}