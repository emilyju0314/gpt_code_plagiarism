Parallel_File_Token_Stream::Parallel_File_Token_Stream(string const &file_name)
    : Text_Token_Stream(), letters_(), letter_(make_shared<letter>(file_name)) {
  Ensure(check_class_invariants());
  Ensure(Parallel_File_Token_Stream::location_() == file_name + ", line 1");
}