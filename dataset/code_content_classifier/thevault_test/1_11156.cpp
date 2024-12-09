int UnicharCompress::DecodeUnichar(const RecodedCharID &code) const {
  int len = code.length();
  if (len <= 0 || len > RecodedCharID::kMaxCodeLen) {
    return INVALID_UNICHAR_ID;
  }
  auto it = decoder_.find(code);
  if (it == decoder_.end()) {
    return INVALID_UNICHAR_ID;
  }
  return it->second;
}