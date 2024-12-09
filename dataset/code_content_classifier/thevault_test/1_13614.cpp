std::string String::ReplaceBetween(const std::string &str,
                                   const std::string &lhs,
                                   const std::string &rhs,
                                   const std::string &replacement) {
  auto offsetStart = str.find(lhs);

  if (std::string::npos == offsetStart) return str;

  size_t offsetEnd = str.find(rhs, offsetStart + 1);

  if (std::string::npos == offsetEnd) return str;

  std::string res = str;
  res.replace(
      offsetStart,
      offsetEnd - offsetStart + rhs.length(),
      replacement);

  return res;
}