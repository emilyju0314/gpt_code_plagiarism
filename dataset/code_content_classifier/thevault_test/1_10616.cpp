static bool IsStrInList(const std::string &str, const std::vector<std::string> &str_list) {
  for (const auto &i : str_list) {
    if (i == str) {
      return true;
    }
  }
  return false;
}