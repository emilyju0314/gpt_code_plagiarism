String_Token_Stream::String_Token_Stream(string const &text)
    : text_(text), pos_(0), messages_(std::string()) {
  Ensure(check_class_invariants());
  Ensure(whitespace() == Text_Token_Stream::default_whitespace);
  Ensure(this->text() == text);
  Ensure(messages() == "");
}