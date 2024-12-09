static bool parseBool(ot::string_view s, bool &result) {
  if (s == "1" || s == "t" || s == "T" || s == "TRUE" || s == "true" ||
      s == "True") {
    result = true;
    return true;
  }
  if (s == "0" || s == "f" || s == "F" || s == "FALSE" || s == "false" ||
      s == "False") {
    result = false;
    return true;
  }
  return false;
}