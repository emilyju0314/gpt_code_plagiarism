static std::string RemoveRedundantZeros(std::string text) {
  text = StringReplace(text, "e+0", "e+", true);
  text = StringReplace(text, "e-0", "e-", true);
  return text;
}