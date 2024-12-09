char *copy_string(const std::string &str) {
  char *copy = (char *)malloc(str.size() + 1);
  if (copy == nullptr) {
    fprintf(stderr,
            "Memory allocation failed during shell autocompletion. Exiting!");
    osquery::Initializer::shutdown(EXIT_FAILURE);
  }
  osquery::platformStrncpy(copy, str.size() + 1, str.c_str(), str.size() + 1);
  return copy;
}