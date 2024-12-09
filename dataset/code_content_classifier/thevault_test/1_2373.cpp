Token Parse_Table::parseforkeyword(Token_Stream &tokens) const {
  // Create a comparator object that will be used to attempt to match keywords
  // in the Token_Stream to keywords in the Parse_Table.  This comparator object
  // incorporates the current settings of the Parse_Table, such as case
  // sensitivity and partial matching options.

  Keyword_Compare_ const comp(flags_);

  // Now begin the process of pulling keywords off the input token stream, and
  // attempting to match these to the keyword table.

  for (;;) {
    Token const token = tokens.shift();

    // The END, EXIT, and ERROR tokens are terminating tokens.  EXIT means the
    // end of the token stream has been reached.  END is used to flag the end of
    // a nested parse, where the result of matching a keyword in one parse table
    // is to begin parsing keywords in a second parse table.  An END indicates
    // that the second parse table should return control to the first parse
    // table.  ERROR means that something went very wrong and we're probably
    // hosed, but it allows some error recovery from within a nested parse
    // table.

    if (token.type() == END || token.type() == EXIT || token.type() == rtt_parser::ERROR) {
      return token;
    }

    // A Parse_Table assumes that every construct begins with a keyword.  This
    // keyword is matched to the keyword table, and if a match is found, control
    // is directed to the associated parse function, which can be written to
    // accept just about any construct you wish.  However, by the time return
    // controls from a parse function, the token stream should be pointing
    // either at a terminating token or the next keyword.

    if (token.type() == KEYWORD) {
      // Attempt to match the keyword to the keyword table.  The following call
      // returns an iterator pointing to the first keyword in the table whose
      // lexical ordering is greater than or equal to the keyword token.  The
      // lexical ordering is supplied by the comp object.

      vector<Keyword>::const_iterator const match =
          lower_bound(vec.begin(), vec.end(), token, comp);

      if (match == vec.end() || comp.kt_comparison(match->moniker, token.text().c_str()) != 0) {
        // The token was not lexically equal to anything in the keyword table.
        // In other words, the keyword is unrecognized by the Parse_Table.  The
        // error recovery procedure is to generate a diagnostic, then pull
        // additional tokens off the token stream (without generating further
        // diagnostics) until one is recognized as either a keyword or a
        // terminating token.  We implement this behavior by setting the
        // is_recovering flag when the first invalid token is encountered, and
        // resetting this flag as soon as a valid token is encountered.
      } else {
        // We have a valid match.  However, depending on Parse_Table options,
        // the match might be ambiguous.  For example if the Parse_Table option
        // to allow partial matches is active, the keyword token may partially
        // match more than one keyword in the keyword table.  Check for an
        // ambiguous match:

        if (match + 1 != vec.end() &&
            comp.kt_comparison(match[1].moniker, token.text().c_str()) == 0) {
          // The match is ambiguous.  This is diagnosed whether or not we are
          // already in recovery mode, but it does put us into recovery mode.

          tokens.report_semantic_error(token, "ambiguous keyword: " + token.text());
        } else {
          // We successfully processed something, so we are no longer in
          // recovery mode.

          try {
            // Call the parse function associated with the keyword.
            match->func(tokens, match->index);

            if (flags_ & ONCE)
            // Quit after parsing a single keyword. This is useful for parse
            // tables for selecting one of a set of short options.
            {
              return Token(END, "");
            }
          } catch (const Syntax_Error &) {
            // If the parse function detects a syntax error, and if it does not
            // have its own error recovery policy (or is unable to recover), it
            // should call tokens.Report_Syntax_Error which generates a
            // diagnostic and throws a Syntax_Error exception. This puts the
            // main parser into recovery mode.
            tokens.report_semantic_error(token, "syntax error: " + token.text());
          }
        }
      }
    }
  }
}