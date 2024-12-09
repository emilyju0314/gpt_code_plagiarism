void Text_Token_Stream::rewind() {
  while (!buffers_.empty())
    buffers_.pop();
  buffer_.clear();
  while (!lines_.empty())
    lines_.pop();
  line_ = 1;

  Token_Stream::rewind();

  Ensure(check_class_invariants());
  Ensure(error_count() == 0);
}