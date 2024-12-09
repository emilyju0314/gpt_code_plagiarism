void Parallel_File_Token_Stream::comment(string const &message) {
  Require(check_class_invariants());

  if (rtt_c4::node() == 0) {
    cerr << message << endl;
  }

  Ensure(check_class_invariants());
}