void Parallel_File_Token_Stream::report(string const &message) {
  Require(check_class_invariants());

  Token token = lookahead();
  // The lookahead must be done on all processors to avoid a potential lockup
  // condition.
  if (rtt_c4::node() == 0) {
    cerr << token.location() << ": " << message << endl;
  }

  Ensure(check_class_invariants());
}