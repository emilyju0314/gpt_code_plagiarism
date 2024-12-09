void Parallel_File_Token_Stream::push_include(std::string &filename) {
  Text_Token_Stream::push_include(filename);
  letters_.push(letter_);
  letter_ = make_shared<letter>(filename);
}