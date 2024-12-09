int UnicharCompress::EncodeUnichar(unsigned unichar_id, RecodedCharID *code) const {
  if (unichar_id >= encoder_.size()) {
    return 0;
  }
  *code = encoder_[unichar_id];
  return code->length();
}