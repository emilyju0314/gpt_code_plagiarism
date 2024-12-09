void Console_Token_Stream::report(Token const &token, string const &message) {
  std::cerr << token.location() << ": " << message << std::endl;

  Ensure(check_class_invariants());
}