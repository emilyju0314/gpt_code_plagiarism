void Text_Token_Stream::pop_include() {
  Check(lines_.size() > 0);

  line_ = lines_.top();
  lines_.pop();
  buffer_ = buffers_.top();
  buffers_.pop();

  Require(check_class_invariants());
}