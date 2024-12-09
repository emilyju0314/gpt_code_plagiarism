void Console_Token_Stream::comment(string const &message) {
  std::cerr << message << std::endl;

  Ensure(check_class_invariants());
}