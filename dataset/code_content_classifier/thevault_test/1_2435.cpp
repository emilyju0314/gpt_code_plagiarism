void String_Token_Stream::report(Token const &token, string const &message) {
  messages_ += token.location() + "\n" + message + '\n';

  Ensure(check_class_invariants());
}