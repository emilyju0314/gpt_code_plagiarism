std::string expandEnvironmentVariables(const std::string& input) {
  std::string text = input;
  autoExpandEnvironmentVariables(text);
  return text;
}