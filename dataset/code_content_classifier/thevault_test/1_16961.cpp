bool AbslParseFlag(absl::string_view src, OptionalString* flag,
                   std::string* error) {
  std::string val;
  if (src.empty())
    flag->reset();
  else if (!absl::ParseFlag(src, &val, error))
    return false;
  *flag = val;
  return true;
}