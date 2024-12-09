bool String::EndsWith(std::string const &str, std::string const &ending) {
  return ending.empty()
      || (ending.size() <= str.size()
          && std::equal(ending.rbegin(), ending.rend(), str.rbegin()));
}