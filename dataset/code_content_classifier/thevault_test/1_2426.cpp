char Text_Token_Stream::peek_(unsigned const pos) {
  while (buffer_.size() <= pos) {
    fill_character_buffer_();
  }

  Ensure(check_class_invariants());
  return buffer_[pos];
}