void UnicharCompress::ComputeCodeRange() {
  code_range_ = -1;
  for (auto &code : encoder_) {
    for (int i = 0; i < code.length(); ++i) {
      if (code(i) > code_range_) {
        code_range_ = code(i);
      }
    }
  }
  ++code_range_;
}