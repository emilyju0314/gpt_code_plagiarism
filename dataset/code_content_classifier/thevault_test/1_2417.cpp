Token Text_Token_Stream::fill_() {
  eat_whitespace_();

  char c = peek_(); // Character at the current cursor position

  string token_location = location_();

  if (c == '\0') {
    // Sentinel value for error or end of file.
    if (end_()) {
      if (lines_.size() > 0) {
        // We're at the end of an included file. Pop up.
        pop_include();
        return fill_();
      } else {
        // We're at the end of the top file.
        Ensure(check_class_invariants());
        return {EXIT, token_location};
      }
    } else {
      // Code only reachable if hardware failure occurs. Code coverage not expected.
      Ensure(check_class_invariants());
      return {rtt_parser::ERROR, token_location};
    }
  } else {
    if (isalpha(c) || c == '_')
    // Beginning of a keyword or END token
    {
      Token Result = scan_keyword();
      Ensure(check_class_invariants());
      return Result;
    } else if (isdigit(c) || c == '.') {
      // A number of some kind.  Note that an initial sign ('+' or '-')
      // is tokenized independently, because it could be interpreted as
      // a binary operator in arithmetic expressions.  It is up to the
      // parser to decide if this is the correct interpretation.
      unsigned const float_length = scan_floating_literal_();
      unsigned const int_length = scan_integer_literal_();
      string text;
      if (float_length > int_length) {
        text.reserve(float_length);
        for (unsigned i = 0; i < float_length; i++) {
          c = pop_char_();
          text += c;
        }
        Ensure(check_class_invariants());
        return {REAL, give(text), give(token_location)};
      } else if (int_length > 0) {
        text.reserve(int_length);
        for (unsigned i = 0; i < int_length; i++) {
          char cc = pop_char_();
          text += cc;
        }
        Ensure(check_class_invariants());
        return {INTEGER, give(text), give(token_location)};
      } else {
        Check(c == '.');
        pop_char_();
        Ensure(check_class_invariants());
        return {'.', give(token_location)};
      }
    } else if (c == '"')
    // Manifest string
    {
      Token Result = scan_manifest_string();
      Ensure(check_class_invariants());
      return Result;
    } else if (c == '#')
    // #directive
    {
      pop_char_();
      eat_whitespace_();
      c = peek_();
      if (!isalpha(c) && c != '_') {
        report_syntax_error("ill-formed #directive");
      } else {
        Token directive = scan_keyword();
        if (directive.text() == "include") {
          eat_whitespace_();
          if (peek_() == '"') {
            Token file = scan_manifest_string();
            string name = file.text();
            // strip end quotes. May allow internal quotes someday ...
            name = name.substr(1, name.size() - 2);
            push_include(name);
            return fill_();
          } else {
            report_syntax_error("#include requires file name in quotes");
          }
        } else {
          report_syntax_error("unrecognized #directive: #" + directive.text());
        }
      }
    } else if (c == '<')
    // Multicharacter OTHER
    {
      pop_char_();
      if (peek_() == '=') {
        pop_char_();
        Ensure(check_class_invariants());
        return {OTHER, "<=", give(token_location)};
      } else {
        Ensure(check_class_invariants());
        return {c, give(token_location)};
      }
    } else if (c == '>')
    // Multicharacter OTHER
    {
      pop_char_();
      if (peek_() == '=') {
        pop_char_();
        Ensure(check_class_invariants());
        return {OTHER, ">=", give(token_location)};
      } else {
        Ensure(check_class_invariants());
        return {c, give(token_location)};
      }
    } else if (c == '&')
    // Multicharacter OTHER
    {
      pop_char_();
      if (peek_() == '&') {
        pop_char_();
        Ensure(check_class_invariants());
        return {OTHER, "&&", give(token_location)};
      } else {
        Ensure(check_class_invariants());
        return {c, give(token_location)};
      }
    } else if (c == '|')
    // Multicharacter OTHER
    {
      pop_char_();
      if (peek_() == '|') {
        pop_char_();
        Ensure(check_class_invariants());
        return {OTHER, "||", give(token_location)};
      } else {
        Ensure(check_class_invariants());
        return {c, give(token_location)};
      }
    } else {
      // OTHER
      pop_char_();
      Ensure(check_class_invariants());
      return {c, give(token_location)};
    }
  }
}