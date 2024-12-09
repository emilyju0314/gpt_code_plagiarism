std::string formatString(std::string str) {
  // Trim left
  std::size_t cutOffset = 0;
  for (auto c : str) {
    if (::isalnum(c))
      break;
    else
      ++cutOffset;
  }
  str = str.substr(cutOffset);

  // Trim right
  cutOffset = 0;
  for (std::size_t i = 0; i < str.size(); ++i) {
    if (::isalnum(str[i]))
      cutOffset = i + 1;
  }
  str = str.substr(0, cutOffset);

  std::replace(str.begin(), str.end(), ' ', '_');
  std::for_each(str.begin(), str.end(), [](char &c) { c = ::toupper(c); });

  return str;
}