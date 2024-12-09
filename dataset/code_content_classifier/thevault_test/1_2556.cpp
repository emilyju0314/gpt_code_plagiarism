void Parallel_File_Token_Stream::rewind() {
  while (!letters_.empty()) {
    letter_ = letters_.top();
    letters_.pop();
  }
  if (letter_ != nullptr)
    letter_->rewind();

  Text_Token_Stream::rewind();
}