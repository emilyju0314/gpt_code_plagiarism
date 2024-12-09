bool SafeParseInt64Array(const std::string& str, std::vector<int64>* parsed_int) {
  static const char kWhiteSpaces[] = " \t\n\v\f\r";
  std::vector<std::string> items = absl::StrSplit(
      str, absl::delimiter::AnyOf(kWhiteSpaces), absl::SkipEmpty());
  parsed_int->assign(items.size(), 0);
  for (int i = 0; i < items.size(); ++i) {
    const char* item = items[i].c_str();
    char* endptr = nullptr;
    (*parsed_int)[i] = strto64(item, &endptr, 10);
    // The whole item should have been consumed.
    if (*endptr != '\0') return false;
  }
  return true;
}