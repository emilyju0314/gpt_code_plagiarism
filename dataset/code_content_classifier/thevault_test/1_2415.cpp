Text_Token_Stream::Text_Token_Stream(set<char> const &ws, bool const no_nonbreaking_ws)
    : buffer_(), whitespace_(ws), no_nonbreaking_ws_(no_nonbreaking_ws) {
  Ensure(check_class_invariants());
  Ensure(ws == whitespace());
  Ensure(line() == 1);
  Ensure(this->no_nonbreaking_ws() == no_nonbreaking_ws);
}