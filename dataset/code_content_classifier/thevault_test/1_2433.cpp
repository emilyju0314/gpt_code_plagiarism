String_Token_Stream::String_Token_Stream(string const &text, set<char> const &ws,
                                         bool const no_nonbreaking_ws)
    : Text_Token_Stream(ws, no_nonbreaking_ws), text_(text), pos_(0), messages_(std::string()) {
  Ensure(check_class_invariants());
  Ensure(whitespace() == ws);
  Ensure(this->text() == text);
  Ensure(messages() == "");
}