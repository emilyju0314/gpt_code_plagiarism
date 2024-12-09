void String_Token_Stream::comment(string const &message) {
  messages_ += message + '\n';

  Ensure(check_class_invariants());
}