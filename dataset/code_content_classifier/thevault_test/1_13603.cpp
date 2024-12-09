bool shellCommandUrl::GetSchemeFromUrl() const {
  if (argc_ < 3) return false;

  std::string kUrl = argv_[2];

  auto offset_start = kUrl.find(':');

  if (offset_start == std::string::npos) return false;

  std::cout << kUrl.substr(0, offset_start);

  return true;
}