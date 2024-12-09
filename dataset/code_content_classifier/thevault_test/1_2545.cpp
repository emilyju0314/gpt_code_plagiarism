void Console_Token_Stream::report(string const &message) {
  Token token = lookahead();
  std::cerr << token.location() << ": " << message << std::endl;

  Ensure(check_class_invariants());
}