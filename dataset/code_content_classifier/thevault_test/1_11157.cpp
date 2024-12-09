bool UnicharCompress::DeSerialize(TFile *fp) {
  if (!fp->DeSerialize(encoder_)) {
    return false;
  }
  ComputeCodeRange();
  SetupDecoder();
  return true;
}