void Parallel_File_Token_Stream::letter::rewind() {
  if (is_io_processor_) {
    infile_.clear(); // Must clear the error/end flag bits.
    infile_.seekg(0);
  }

  at_eof_ = at_error_ = false;

  Ensure(check_class_invariants());
}