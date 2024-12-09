void UnicharCompress::SetupDirect(const std::vector<RecodedCharID> &codes) {
  encoder_ = codes;
  ComputeCodeRange();
  SetupDecoder();
}