bool shellCommandClipboard::ExtractBetween() const {
  if (argc_ < 3) return false;

  std::string kHaystack;
  clip::get_text(kHaystack);

  int arg_offset_before = 2, arg_offset_after = 3;

  const std::string kBefore = argv_[arg_offset_before];

  const std::string kAfter = argc_ <= arg_offset_after
                             ? ""
                             : argv_[arg_offset_after];

  kHaystack = helper::String::GetSubStrBetween(
      kHaystack, kBefore.c_str(), kAfter.c_str());

  std::cout << kHaystack;

  clip::set_text(kHaystack);

  return true;
}