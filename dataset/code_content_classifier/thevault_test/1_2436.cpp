void String_Token_Stream::report(string const &message) {
  Token token = lookahead();
  messages_ += token.location() + "\n" + message + '\n';

  Ensure(check_class_invariants());
}