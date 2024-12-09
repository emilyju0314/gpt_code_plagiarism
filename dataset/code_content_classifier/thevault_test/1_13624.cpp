bool shellCommandString::ExtractBetween(std::string str) const {
  if (argc_ < 3) return false;

  std::string kHaystack;
  int arg_offset_before = 3, arg_offset_after = 4;

  kHaystack = str.empty()
              // Haystack is given as CLI argument
              ? argv_[2]
              // Haystack is given as function parameter
              : str;

  const std::string kBefore = argv_[arg_offset_before];

  const std::string kAfter = argc_ <= arg_offset_after
                             ? ""
                             : argv_[arg_offset_after];

  std::cout << helper::String::GetSubStrBetween(
      kHaystack, kBefore.c_str(), kAfter.c_str());

  return true;
}