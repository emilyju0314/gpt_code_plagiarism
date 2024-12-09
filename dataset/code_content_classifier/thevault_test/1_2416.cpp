Text_Token_Stream::Text_Token_Stream() : buffer_(), whitespace_(default_whitespace) {
  Ensure(check_class_invariants());
  Ensure(whitespace() == default_whitespace);
  Ensure(line() == 1);
  Ensure(!no_nonbreaking_ws());
}