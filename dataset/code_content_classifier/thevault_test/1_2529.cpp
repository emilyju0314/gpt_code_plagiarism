unsigned parse_debug_options(Token_Stream &tokens, unsigned const parent) {
  using namespace rtt_parser;

  unsigned Result = parent;

  Token token = tokens.lookahead();
  while (token.type() == KEYWORD || token.text() == "!") {
    bool mask_out = (token.text() == "!");
    if (mask_out) {
      tokens.shift();
      token = tokens.lookahead();
    }
    unsigned mask = get_debug_option(token.text());
    if (mask != 0) {
      if (mask_out) {
        Result = Result & ~mask;
      } else {
        Result = Result | mask;
      }
      tokens.shift();
    } else {
      tokens.check_syntax(!mask_out, "trailing '!'");
      return Result;
    }
    token = tokens.lookahead();
  }
  return Result;
}