bool shellCommandClipboard::ReplaceLast() const {
  if (argc_ < 3) return false;

  std::string kHaystack;
  clip::get_text(kHaystack);

  int arg_offset_needle = 2, arg_offset_replacement = 3;

  const std::string kNeedle = argv_[arg_offset_needle];

  const std::string kReplacement = argc_ <= arg_offset_replacement
                                   ? ""
                                   : argv_[arg_offset_replacement];

  helper::String::ReplaceLast(&kHaystack, kNeedle, kReplacement);

  std::cout << kHaystack;

  clip::set_text(kHaystack);

  return true;
}