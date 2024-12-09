bool AbslParseFlag(absl::string_view src, OptionalInt* flag,
                   std::string* error) {
  int val;
  if (src.empty())
    flag->reset();
  else if (!absl::ParseFlag(src, &val, error))
    return false;
  *flag = val;
  return true;
}