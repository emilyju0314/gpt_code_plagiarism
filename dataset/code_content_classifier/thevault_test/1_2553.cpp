void Parallel_File_Token_Stream::report(Token const &token, string const &message) {
  if (rtt_c4::node() == 0) {
    cerr << token.location() << ": " << message << endl;
  }
  Ensure(check_class_invariants());
}