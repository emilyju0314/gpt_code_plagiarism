Console_Token_Stream::Console_Token_Stream(set<char> const &ws, bool const no_nonbreaking_ws)
    : Text_Token_Stream(ws, no_nonbreaking_ws) {
  Ensure(check_class_invariants());
  Ensure(Console_Token_Stream::location_() == "input");
  Ensure(whitespace() == ws);
  Ensure(this->no_nonbreaking_ws() == no_nonbreaking_ws);
}