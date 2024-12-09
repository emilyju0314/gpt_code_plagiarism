bool shellCommandClipboard::ReplaceBetween() const {
  if (argc_ < 3) return false;

  std::string kHaystack;
  clip::get_text(kHaystack);

  int arg_offset_before = 2, arg_offset_after = 3, arg_offset_replacement = 4;

  const std::string kBefore = argv_[arg_offset_before];
  const std::string kAfter = argv_[arg_offset_after];

  const std::string kReplacement = argc_ <= arg_offset_replacement
                                   ? ""
                                   : argv_[arg_offset_replacement];

  kHaystack =
      helper::String::ReplaceBetween(kHaystack, kBefore, kAfter, kReplacement);

  if (kHaystack.empty()) return false;

  std::cout << kHaystack;

  clip::set_text(kHaystack);

  return true;
}