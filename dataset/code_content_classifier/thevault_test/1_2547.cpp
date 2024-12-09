void Console_Token_Stream::rewind() {
  cin.clear(); // Must clear the error/end flag bits.

  // [2015-09-01 KT] After talking to Kent about this implementation, we decided
  // that it does not make sense to rewind an interactive standard input buffer.
  // In fact, if this is done under an MPI environment (e.g. mpirun -np 1, aprun
  // -n 1, etc. ), the seekg() will return an error condition.

  // cin.seekg(0);

  Text_Token_Stream::rewind();

  Ensure(check_class_invariants());
  Ensure(cin.rdstate() == 0);
  Ensure(location_() == "input");
}